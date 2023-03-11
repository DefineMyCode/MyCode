//#include <list>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <assert.h>
#include <Windows.h>
using namespace std;

typedef struct ListNode
{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* ListRevers(ListNode* pHead)
{
    ListNode* prev = NULL;
    ListNode* cur = pHead;
    ListNode* next = pHead->next;
    while (cur != next)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (next != NULL)
            next = next->next;
    }
    return prev;
}
bool isPalindrome(ListNode* pHead) {
    if (pHead == NULL||pHead->next==NULL)
        return true;
    ListNode* fast = pHead;
    ListNode* slow = pHead;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    //�Ͽ�ǰ�벿�����벿�ֲ����ú󲿷�
    ListNode* MidHead = slow->next;
    slow->next = NULL;
    ListNode* reversMid = ListRevers(MidHead);
    //���м�ͷ����Ϊ���ú��ͷ
    MidHead = reversMid;
    while (reversMid != NULL)
    {
        if (reversMid->val != pHead->val)
        {
            //���Ͽ� ���� �Ľڵ㻹ԭ
            ListNode* QuoMidHead = ListRevers(MidHead);
            slow->next = QuoMidHead;
            return false;
        }
        reversMid = reversMid->next;
        pHead = pHead->next;
    }
    //���Ͽ� ���� �Ľڵ㻹ԭ
    ListNode* QuoMidHead = ListRevers(MidHead);
    slow->next = QuoMidHead;
    return true;
}

void PrintList(ListNode* pHead)
{
    while (pHead != NULL)
    {
        cout << pHead->val << "->";
        pHead = pHead->next;
    }
    cout << "NULL";
    cout << endl;
}

void ListDestory(ListNode* pHead)
{
    assert(pHead != NULL);
    ListNode* next = pHead->next;
    while (pHead != NULL)
    {
        delete pHead;
        pHead = next;
        if(next!=NULL)
            next = next->next;
    }
    cout << "�ɹ�������list " << endl;
}

void test()
{
    srand((unsigned int)time(0));
    ListNode* pHead;
    int halflen = rand() % 30;
    int* vals = new int[halflen];
    //����ڵ��е�Ԫ��
    if (halflen != 0)
    {
        for (int i = 0;i < halflen;i++)
        {
            vals[i] = rand() % 100;
        }
    }
    else
        pHead = NULL;
    //����list ǰ�벿��
    pHead = new ListNode;
    pHead->val = vals[0];
    pHead->next = NULL;
    ListNode* prev = pHead;

    //���ô���ֵ
    //int faultslen = rand() %  halflen + 1;
    //int faultslen = 1;
    //int* faults = new int[faultslen];

    ////����ֵ������λ��
    //for (int i = 0;i < faultslen;i++)
    //    faults[i] = rand() % halflen + 1;

    for (int i = 1;i < halflen;i++)
    {
        ListNode* newnode = new ListNode;
        
        //���ɴ���ֵ
        //for (int j = 0;j < faultslen;j++)
        //{
        //    if (faults[j] == i)        
        //        newnode->val = rand() % 1000 + 501;
        //}
        //if( ! (newnode->val>=501) )
            newnode->val = vals[i];   
        newnode->next = NULL;
        prev->next = newnode;
        prev = newnode;
    }
    //�м䲿��
    //�������ڵ�
   /* ListNode* Midnode = new ListNode;
    Midnode->val = rand() % 5000;
    Midnode->next = NULL;
    prev->next = Midnode;*/

    //ż�����ڵ�
    ListNode* Midnode = prev;

    
    //����list ��벿��

    //���ô���ֵ
    //int faultslenS = rand() % halflen + 1;
    //int faultslenS = 1;
    //int* faultsS = new int[faultslenS];

    //����ֵ������λ��
    //for (int i = 0;i < faultslenS;i++)
    //    faultsS[i] = rand() % halflen + 1;

    ListNode* Secondhalf = new ListNode;
    Secondhalf->val = vals[halflen-1];
    Secondhalf->next = NULL;
    prev = Secondhalf;
    for (int i = halflen-2;i >= 0;i--)
    {
        ListNode* newnode = new ListNode;
        //���ɴ���ֵ
        //for (int j = 0;j < faultslenS;j++)
        //{
        //    if (faultsS[j] == i)
        //        newnode->val = rand() % 1000 + 501;
        //}
        //if (!(newnode->val >= 501))
            newnode->val = vals[i];
  
        newnode->next = NULL;
        prev->next = newnode;
        prev = newnode;
    }
    Midnode->next = Secondhalf;
    PrintList(pHead);
    if (isPalindrome(pHead))
    {
        cout << "true" << endl;
        PrintList(pHead);
    }
    else
    {
        cout << "false" << endl;
        PrintList(pHead);
    }
    ListDestory(pHead);
    delete[] vals;
    //delete[] faults;
    //delete[] faultsS;
}

int main()
{
    
    for (int i = 0;i < 20;i++)
    {
        test();
        Sleep(1000);
        cout << endl << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    }
	return 0;
}