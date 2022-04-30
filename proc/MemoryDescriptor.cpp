#include "MemoryDescriptor.h"
#include "Kernel.h"
#include "PageManager.h"
#include "Machine.h"
#include "PageDirectory.h"
#include "Video.h"

void MemoryDescriptor::Initialize()
{
	KernelPageManager& kernelPageManager = Kernel::Instance().GetKernelPageManager();
	
	/* m_UserPageTableArray��Ҫ��AllocMemory()���ص������ڴ��ַ + 0xC0000000 */
//	this->m_UserPageTableArray = (PageTable*)(kernelPageManager.AllocMemory(sizeof(PageTable) * USER_SPACE_PAGE_TABLE_CNT) + Machine::KERNEL_SPACE_START_ADDRESS);
//	this->m_UserPageTableArray = NULL;
}

void MemoryDescriptor::Release()
{
	KernelPageManager& kernelPageManager = Kernel::Instance().GetKernelPageManager();
//	if ( this->m_UserPageTableArray )
//	{
//		kernelPageManager.FreeMemory(sizeof(PageTable) * USER_SPACE_PAGE_TABLE_CNT, (unsigned long)this->m_UserPageTableArray - Machine::KERNEL_SPACE_START_ADDRESS);
//		this->m_UserPageTableArray = NULL;
//	}
}

unsigned int MemoryDescriptor::MapEntry(unsigned long virtualAddress, unsigned int size, unsigned long phyPageIdx, bool isReadWrite)
{	
//	unsigned long address = virtualAddress - USER_SPACE_START_ADDRESS;
//
//	//�����pagetable����һ����ַ��ʼӳ��
//	unsigned long startIdx = address >> 12;
//	unsigned long cnt = ( size + (PageManager::PAGE_SIZE - 1) )/ PageManager::PAGE_SIZE;
//
//	PageTableEntry* entrys = (PageTableEntry*)this->m_UserPageTableArray;
//	for ( unsigned int i = startIdx; i < startIdx + cnt; i++, phyPageIdx++ )
//	{
//		entrys[i].m_Present = 0x1;
//		entrys[i].m_ReadWriter = isReadWrite;
//		entrys[i].m_PageBaseAddress = phyPageIdx;
//	}
	return phyPageIdx;
}

void MemoryDescriptor::MapTextEntrys(unsigned long textStartAddress, unsigned long textSize, unsigned long textPageIdx)
{
	this->MapEntry(textStartAddress, textSize, textPageIdx, false);
}
void MemoryDescriptor::MapDataEntrys(unsigned long dataStartAddress, unsigned long dataSize, unsigned long dataPageIdx)
{
	this->MapEntry(dataStartAddress, dataSize, dataPageIdx, true);
}

void MemoryDescriptor::MapStackEntrys(unsigned long stackSize, unsigned long stackPageIdx)
{
	unsigned long stackStartAddress = (USER_SPACE_START_ADDRESS + USER_SPACE_SIZE - stackSize) & 0xFFFFF000;
	this->MapEntry(stackStartAddress, stackSize, stackPageIdx, true);
}

PageTable* MemoryDescriptor::GetUserPageTableArray()
{
//	return this->m_UserPageTableArray;
	return NULL;
}
unsigned long MemoryDescriptor::GetTextStartAddress()
{
	return this->m_TextStartAddress;
}
unsigned long MemoryDescriptor::GetTextSize()
{
	return this->m_TextSize;
}
unsigned long MemoryDescriptor::GetDataStartAddress()
{
	return this->m_DataStartAddress;
}
unsigned long MemoryDescriptor::GetDataSize()
{
	return this->m_DataSize;
}
unsigned long MemoryDescriptor::GetStackSize()
{
	return this->m_StackSize;
}

bool MemoryDescriptor::EstablishUserPageTable( unsigned long textVirtualAddress, unsigned long textSize, unsigned long dataVirtualAddress, unsigned long dataSize, unsigned long stackSize )
{
	User& u = Kernel::Instance().GetUser();

	/* ��������������û��������8M�ĵ�ַ�ռ����� */
	if ( textSize + dataSize + stackSize  + PageManager::PAGE_SIZE > USER_SPACE_SIZE - textVirtualAddress)
	{
		u.u_error = User::ENOMEM;
		Diagnose::Write("u.u_error = %d\n",u.u_error);
		return false;
	}
	m_TextSize=textSize;
	m_DataSize=dataSize;
	m_StackSize=stackSize;
//	this->ClearUserPageTable();
//
//	/* �������ʼ��ַphyPageIndexΪ0��Ϊ���Ķν�����Ե�ַӳ�ձ� */
//	unsigned int phyPageIndex = 0;
//	phyPageIndex = this->MapEntry(textVirtualAddress, textSize, phyPageIndex, false);
//
//	/* �������ʼ��ַphyPageIndexΪ1��ppda��ռ��1ҳ4K��С�����ڴ棬Ϊ���ݶν�����Ե�ַӳ�ձ� */
//	phyPageIndex = 1;
//	phyPageIndex = this->MapEntry(dataVirtualAddress, dataSize, phyPageIndex, true);
//
//	/* ���������ݶ�֮��Ϊ��ջ�ν�����Ե�ַӳ�ձ� */
//	unsigned long stackStartAddress = (USER_SPACE_START_ADDRESS + USER_SPACE_SIZE - stackSize) & 0xFFFFF000;
//	this->MapEntry(stackStartAddress, stackSize, phyPageIndex, true);

	/* ����Ե�ַӳ�ձ��������Ķκ����ݶ����ڴ��е���ʼ��ַpText->x_caddr��p_addr�������û�̬�ڴ�����ҳ��ӳ�� */
	this->MapToPageTable();
	return true;
}

void MemoryDescriptor::ClearUserPageTable()
{
//	User& u = Kernel::Instance().GetUser();
//	PageTable* pUserPageTable = u.u_MemoryDescriptor.m_UserPageTableArray;
//
//	unsigned int i ;
//	unsigned int j ;
//
//	for (i = 0; i < Machine::USER_PAGE_TABLE_CNT; i++)
//	{
//		for (j = 0; j < PageTable::ENTRY_CNT_PER_PAGETABLE; j++ )
//		{
//			pUserPageTable[i].m_Entrys[j].m_Present = 0;
//			pUserPageTable[i].m_Entrys[j].m_ReadWriter = 0;
//			pUserPageTable[i].m_Entrys[j].m_UserSupervisor = 1;
//			pUserPageTable[i].m_Entrys[j].m_PageBaseAddress = 0;
//		}
//	}

}

void MemoryDescriptor::MapToPageTable()
{
	User& u = Kernel::Instance().GetUser();
	unsigned int TextPageCount = (m_TextSize+(PageManager::PAGE_SIZE - 1))/PageManager::PAGE_SIZE;
	unsigned int DataPageCount = (m_DataSize+(PageManager::PAGE_SIZE - 1))/PageManager::PAGE_SIZE;
	unsigned int StackPageCount = (m_StackSize+(PageManager::PAGE_SIZE - 1))/PageManager::PAGE_SIZE;
	unsigned int DataIndex = 1;
	unsigned int TextIndex = 0;

	PageTable* pUserPageTable = Machine::Instance().GetUserPageTableArray();
	unsigned int textAddress = 0;
	if ( u.u_procp->p_textp != NULL )
	{
		textAddress = u.u_procp->p_textp->x_caddr;
	}
	for (unsigned int i = 0; i < Machine::USER_PAGE_TABLE_CNT; i++)
	{
		for ( unsigned int j = 0; j < PageTable::ENTRY_CNT_PER_PAGETABLE; j++ )
		{
			pUserPageTable[i].m_Entrys[j].m_Present = 0;   //����0
			if(i==0)//��һ��ҳ��Ϊ��
				continue;
			if(j>=1&&j<TextPageCount + 1)//�����
			{
				pUserPageTable[i].m_Entrys[j].m_Present = 1;
				pUserPageTable[i].m_Entrys[j].m_ReadWriter = 0;
				pUserPageTable[i].m_Entrys[j].m_PageBaseAddress = TextIndex+ (textAddress >> 12);
				TextIndex++;
			}
			else if(j>TextPageCount && j<=TextPageCount+DataPageCount)//���ݶ�
			{
				pUserPageTable[i].m_Entrys[j].m_Present = 1;
				pUserPageTable[i].m_Entrys[j].m_ReadWriter = 1;
				pUserPageTable[i].m_Entrys[j].m_PageBaseAddress = DataIndex + (u.u_procp->p_addr >> 12);
				DataIndex++;
			}
			else if(j>=PageTable::ENTRY_CNT_PER_PAGETABLE-StackPageCount)//��ջ��
			{
				pUserPageTable[i].m_Entrys[j].m_Present = 1;
				pUserPageTable[i].m_Entrys[j].m_ReadWriter = 1;
				pUserPageTable[i].m_Entrys[j].m_PageBaseAddress = DataIndex+ (u.u_procp->p_addr >> 12);
				DataIndex++;
			}
		}
	}

	pUserPageTable[0].m_Entrys[0].m_Present = 1;
	pUserPageTable[0].m_Entrys[0].m_ReadWriter = 1;
	pUserPageTable[0].m_Entrys[0].m_PageBaseAddress = 0;

	FlushPageDirectory();
}
//
//void MemoryDescriptor::MapToPageTable()
//{
//	User& u = Kernel::Instance().GetUser();
//
//	if(u.u_MemoryDescriptor.m_UserPageTableArray == NULL)
//		return;
//
//	PageTable* pUserPageTable = Machine::Instance().GetUserPageTableArray();
//	unsigned int textAddress = 0;
//	if ( u.u_procp->p_textp != NULL )
//	{
//		textAddress = u.u_procp->p_textp->x_caddr;
//	}
//
//	for (unsigned int i = 0; i < Machine::USER_PAGE_TABLE_CNT; i++)
//	{
//		for ( unsigned int j = 0; j < PageTable::ENTRY_CNT_PER_PAGETABLE; j++ )
//		{
//			pUserPageTable[i].m_Entrys[j].m_Present = 0;   //����0
//
//			if ( 1 == this->m_UserPageTableArray[i].m_Entrys[j].m_Present )
//			{
//				/* ֻ�����Ա�ʾ���Ķζ�Ӧ��ҳ����pText->x_caddrΪ�ڴ���ʼ��ַ */
//				if ( 0 == this->m_UserPageTableArray[i].m_Entrys[j].m_ReadWriter )
//				{
//					pUserPageTable[i].m_Entrys[j].m_Present = 1;
//					pUserPageTable[i].m_Entrys[j].m_ReadWriter = this->m_UserPageTableArray[i].m_Entrys[j].m_ReadWriter;
//					pUserPageTable[i].m_Entrys[j].m_PageBaseAddress = this->m_UserPageTableArray[i].m_Entrys[j].m_PageBaseAddress + (textAddress >> 12);
//				}
//				/* ��д���Ա�ʾ���ݶζ�Ӧ��ҳ����p_addrΪ�ڴ���ʼ��ַ */
//				else if ( 1 == this->m_UserPageTableArray[i].m_Entrys[j].m_ReadWriter )
//				{
//					pUserPageTable[i].m_Entrys[j].m_Present = 1;
//					pUserPageTable[i].m_Entrys[j].m_ReadWriter = this->m_UserPageTableArray[i].m_Entrys[j].m_ReadWriter;
//					pUserPageTable[i].m_Entrys[j].m_PageBaseAddress = this->m_UserPageTableArray[i].m_Entrys[j].m_PageBaseAddress + (u.u_procp->p_addr >> 12);
//				}
//			}
//		}
//	}
//
//	pUserPageTable[0].m_Entrys[0].m_Present = 1;
//	pUserPageTable[0].m_Entrys[0].m_ReadWriter = 1;
//	pUserPageTable[0].m_Entrys[0].m_PageBaseAddress = 0;
//
//	FlushPageDirectory();
//}