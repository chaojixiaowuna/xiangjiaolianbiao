﻿//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
//题目数据 保证 整个链式结构中不存在环。
//注意，函数返回结果后，链表必须 保持其原始结构 。


//思路一 遍历两个链表 将第一个链表的元素与第二个链表的所有元素比较
//#include<stdio.h>
//#include<stdlib.h>
// struct ListNode 
// {
//      int val;
//     struct ListNode *next;
// };
// 
//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur=head;
//	while(cur)
//	{
//		printf("%d",cur->val);
//		cur=cur->next;
//	}
//}
//void ListDestroy(struct ListNode** tmp)
//{
//	struct ListNode* cur=*tmp;
//	while(cur)
//	{
//		*tmp=(*tmp)->next;
//		free(cur);
//		cur=(*tmp);
//	}
//}
//
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//	struct ListNode *head=headB;
//	while(headA)
//	{
//		head=headB;
//		while(head)
//		{
//
//		   if(headA==head)
//			   return headA;
//		   else
//		   {
//			    head=head->next;
//	   	   }
//
//		}
//			headA=headA->next;
//	}
//	return NULL;
//}
//int main()
//{
//	struct ListNode* n1=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n6=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* tmp;
//	n1->val=1;
//	n2->val=2;
//	n3->val=3;
//	n4->val=4;
//	n5->val=5;
//	n6->val=6;
//	n1->next=n2;
//	n2->next=n5;
//	n5->next=n6;
//	n3->next=n4;
//	n4->next=n5;
//	n5->next=n6;
//	n6->next=NULL;
//	tmp=getIntersectionNode(n1,n3);
//	ListPrint(tmp);
//	ListDestroy(&tmp);
//	return 0;
//}
//时间复杂度O（N^2）


//思路二 逆转链表 找不同的元素  error
//#include<stdio.h>
//#include<stdlib.h>
// struct ListNode 
// {
//      int val;
//     struct ListNode *next;
// };
// 
//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur=head;
//	while(cur)
//	{
//		printf("%d",cur->val);
//		cur=cur->next;
//	}
//}
//void ListDestroy(struct ListNode** tmp)
//{
//	struct ListNode* cur=*tmp;
//	while(cur)
//	{
//		*tmp=(*tmp)->next;
//		free(cur);
//		cur=(*tmp);
//	}
//}
//void ReverseList(struct ListNode** head)
//{
//	struct ListNode* cur=*head;
//	struct ListNode* tmp=NULL;
//	struct ListNode* newhead=NULL;
//	while(cur)
//	{
//		newhead=cur->next;
//		cur->next=tmp;
//		tmp=cur;
//		cur=newhead;
//	}
//	*head=tmp;
//}
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//	struct ListNode *head=NULL;
//	ReverseList(&headA);
//	ReverseList(&headB);
//	while(headA==headB)
//	{
//		head=headA;
//		headA=headA->next;
//		headB=headB->next;
//	}
//	return head;
//}
//int main()
//{
//	struct ListNode* n1=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n6=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* tmp;
//	n1->val=1;
//	n2->val=2;
//	n3->val=3;
//	n4->val=4;
//	n5->val=5;
//	n6->val=6;
//	n1->next=n2;
//	n2->next=n5;
//	n5->next=n6;
//	n3->next=n4;
//	n4->next=n5;
//	n5->next=n6;
//	n6->next=NULL;
//	tmp=getIntersectionNode(n1,n3);
//	ListPrint(tmp);
//	ListDestroy(&tmp);
//	return 0;
//}


//思路三 便利两个链表 比较最后一个节点是否相等 想等便相交 不等则没有相交的节点
//统计两个链表的长度m和n，长的先走m-n步，再同步走 找到相同的即为开始节点
#include<stdio.h>
#include<stdlib.h>
 struct ListNode 
 {
      int val;
     struct ListNode *next;
 };
 
void ListPrint(struct ListNode* head)
{
	struct ListNode* cur=head;
	while(cur)
	{
		printf("%d",cur->val);
		cur=cur->next;
	}
}
void ListDestroy(struct ListNode** tmp)
{
	struct ListNode* cur=*tmp;
	while(cur)
	{
		*tmp=(*tmp)->next;
		free(cur);
		cur=(*tmp);
	}
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode* cur1 = headA;
	struct ListNode* cur2 = headB;
	struct ListNode* tmp1 = NULL;
	struct ListNode* tmp2 = NULL;
	int count1 = 0, count2 = 0;
	//判断是否相交
	while (cur1)
	{
		tmp1 = cur1;
		cur1 = cur1->next;
		count1++;
	}
	while (cur2)
	{
		tmp2 = cur2;
		cur2 = cur2->next;
		count2++;
	}
	if (tmp1 != tmp2)
	{
		return NULL;
	}
	else
	{
		if (count1 < count2)
		{
			while (count2 - count1)
			{
				headB = headB->next;
			}
			while (headA != headB)
			{
				headA = headA->next;
				headB = headB->next;
			}
			return headB;
		}
	}
	return NULL;
}
//void defend(struct ListNode* use)
//{
//	if (use == NULL)
//		exit(1);
//}
int main()
{
	struct ListNode* n1=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tmp;
	//defend(n1);
	//defend(n2);
	//defend(n3);
	//defend(n4);
	//defend(n5);
	//defend(n6);
	if (n1 != NULL)
	{
		n1->val = 1;
	}
	else exit(-1);
	if (n2 != NULL)
	{
		n2->val = 2;
	}
	else exit(-1);
	if (n3 != NULL)
	{
		n3->val = 3;
	}
	else exit(-1);
	if (n4 != NULL)
	{
		n4->val = 4;
	}
	else exit(-1);
	if (n5 != NULL)
	{
		n5->val = 5;
	}
	else exit(-1);
	if (n6 != NULL)
	{
		n6->val = 6;
	}
	else exit(-1);
	n1->next=n2;
	n2->next=n5;
	n5->next=n6;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=NULL;
	tmp=getIntersectionNode(n1,n3);
	ListPrint(tmp);
	ListDestroy(&tmp);
	return 0;
}