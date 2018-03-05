/** Link List Implementation File
 *  @author     Sahil Gupta
 *  @date       03 March 2018
 */
#include <iostream>
#include <set>
#include <stack>
#include <unordered_set>

#include "LinkList.h"

using namespace std;

void LinkList::insert(int x)
{
	Node *tmp = head;
	if(!head) 
		head = new Node(x);
	else {
		while (tmp->next) tmp = tmp->next;
		tmp->next = new Node(x);
	}
}

void LinkList::insert(Node *node)
{
    Node *tmp = head;
    if (!head)
        head = node;
    else {
        while (tmp->next) tmp = tmp->next;
        tmp->next = node;
    }
}

void LinkList::deleteNode(int x)
{

}

void LinkList::clear()
{
    Node *cur;
    while(head) {
        cur = head;
        head=head->next;
        delete cur;
    }
}

int LinkList::length()
{
    Node* cur = head;
    int i;

    for(i=0; cur; ++i, cur = cur->next);

    return i;
}

void LinkList::display()
{
	Node *tmp = head;
	while (tmp->next) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
    cout << tmp->data << endl;
}

void LinkList::remove_duplicates()
{
    Node *cur = head;
    Node *prev = head;
	unordered_set<int> listset; // Set of unique data
    pair<unordered_set<int>::iterator, bool > ret;

	while(cur) {
		cout<<"Checking :"<<cur->data<<endl;
		
        // Insert in set
        ret = listset.insert(cur->data);
		if(ret.second == false) {
			cout << "Detected Dup : " << cur->data << endl;			
			prev->next = cur->next;
			delete cur;
			cur = prev->next;
		}
		else {
			if (cur != head)
				prev = prev->next;
            cur = cur->next;
		}
	}
}

Node* LinkList::nthLast(int n)
{
    Node *cur = head;
    Node *nth = head;

    for (int i=1; i<=n; i++)
        if(cur->next != nullptr) 
            cur = cur->next;
        else if (i == n)
            return head;
        else
            return nullptr;

    while (cur != nullptr) {
        cur = cur->next;
        nth = nth ->next;
    }

    return nth;
}

void LinkList::partition_stable(int x)
{
    Node *headstart = nullptr, *tailstart = nullptr;
    Node *headend = nullptr, *tailend = nullptr;
    Node *cur = head;

    while (cur != nullptr)
    {
        if (cur->data < x)
            if (headend == nullptr)
                headstart = headend = cur;
            else {
                headend->next = cur;
                headend = cur;
            }
        else
            if(tailend == nullptr)
                tailstart = tailend = cur;
            else {
                tailend->next = cur;
                tailend = cur;
            }
        cur = cur->next;
    }

    if(headend != nullptr) 
        headend->next = tailstart;
    else
        headstart = tailstart;      //All elements greater than partition
        
    if(tailend != nullptr)
        tailend->next = nullptr;

    head = headstart;
}

void LinkList::partition(int x)
{
    Node *head_ = head, *tail_ = head, *cur = head;

    while (cur != nullptr)
    {
        Node *next = cur->next;
        if (cur->data < x) {
                cur->next = head_;
                head_ = cur;
            }
        else {
            tail_->next = cur;
            tail_ = cur;
        }
        cur = next;
    }

    tail_->next = nullptr;
    head = head_;
}

bool LinkList::IsPalindrome()
{
    bool bRet;
    
    NodeState* result = checkPalindrome(head, length());
    bRet = result->status;
    delete result;

    return bRet;
}

LinkList* LinkList::SumBackwardNo(LinkList *b)
{
    LinkList *a = this;
    LinkList *result = new LinkList();
    Node *acur = a->head, *bcur = b->head;
    int sum = 0, carry = 0;

    while (acur || bcur || carry) {
        sum = 0;
        if (acur) {
            sum += acur->data;
            acur = acur->next;
        }
        if (bcur) {
            sum += bcur->data;
            bcur = bcur->next;
        }
        sum += carry;
        result->insert(sum % 10);
        carry = sum / 10;
    }
    return result;
}

LinkList::NodeState* LinkList::checkPalindrome(Node* node, int length)
{
    // Base Case
    if (length <= 0) { //Even Nodes or one node
        return new NodeState(node, true);
    }
    else if (length == 1) { //Odd Nodes - We are at middle node, return next
        return new NodeState(node->next, true);
    }

    // Recurse: till we reach middle node
    NodeState* result = checkPalindrome(node->next, length-2);

    // Do Comparison
    if(result->status == false) //If substring is not palindrome
        return result;

    //Check for palindrome
    result->status = (node->data == result->node->data);
    result->node = result->node->next;

    return result;
}

bool LinkList::IsPalindrome_stack()
{
    Node *slow = head, *fast = head;
    stack<int> s;

    while(fast && fast->next) { // even
        s.push(slow->data);     // push start to mid on stack
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast) { //odd no of nodes, we are at mid, skip it
            slow = slow->next;
    }

    while (slow) {
        if(slow->data != s.top())
            return false;
        s.pop();
        slow = slow->next;
    }

    return true;
}

Node* LinkList::IfIntersect(LinkList* b)
{
    LinkList* a = (LinkList *)this;

    Node *acur = a->head, *bcur = b->head;
    int alen = 1, blen = 1;

    if(!acur || !bcur) 
        return nullptr;

    while(acur->next) {
        acur = acur->next;
        alen++;
    }
    while (bcur->next) {
        bcur = bcur->next;
        blen++;
    }

    if(acur != bcur) //ends should be same if list intersect
        return nullptr; 

    if (alen > blen) {
        acur = a->nthLast(blen);
        bcur = b->head;
    }
    else {
        bcur = b->nthLast(alen);
        acur = a->head;
    }

    while (acur != bcur) {
        acur = acur->next;
        bcur = bcur->next;
    }

    return acur;
}

//Bug : if loop at start
bool LinkList::IsLoop()
{
    Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop Detected. This node is collision point
        if (slow == fast) {
            cout << "\nLoop Detected at Node : " << slow->data;
            break;
        }
    }

    //No Loop
    if (!fast || !fast->next) {
        cout << "\nNo Loop";
        return false;
    }

    // Detect Loop Start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    cout << "\nLoop Start Node : " << slow->data;
    //remove loop
    //fast->next = nullptr;

    return true;
}

void main()
{
    LinkList l;
    l.insert(45); l.insert(35); l.insert(25); l.insert(15); l.insert(5); l.insert(2);
	l.insert(2); l.insert(5); l.insert(15); l.insert(25); l.insert(25); 
    l.insert(35); l.insert(45);
    l.display();

    //1-------------------------------------------------------------------
    l.remove_duplicates();
    l.display();
    
    //2-------------------------------------------------------------------
    Node *LastNth = l.nthLast(7);
    if(LastNth != nullptr) cout << "Last Nth : " << LastNth->data;
    
    //3-------------------------------------------------------------------
    l.clear();
    for (int i = 0; i < 10; ++i) {
        l.insert(rand() % 10);
    }
    l.display();
    l.partition(10);
    l.display();
    
    //4-------------------------------------------------------------------
    cout << endl << "Palindrome Check" << endl;

    l.display();
    cout << "Is Palindrome : " << l.IsPalindrome_stack() << endl;

    l.clear();
    l.insert(1); l.insert(2); l.insert(3); l.insert(2); l.insert(1);  
    l.display();
    cout<< "Is Palindrome : " << l.IsPalindrome_stack() << endl;

    l.clear();
    l.insert(1); l.insert(2); l.insert(2); l.insert(1);
    l.display();
    cout << "Is Palindrome : " << l.IsPalindrome_stack() << endl;

    l.clear();
    l.insert(1); l.insert(1);
    l.display();
    cout << "Is Palindrome : " << l.IsPalindrome_stack() << endl;

    l.clear();
    l.insert(1);
    l.display();
    cout << "Is Palindrome : " << l.IsPalindrome_stack() << endl;
    
    //5-------------------------------------------------------------------
    cout << " Intersection" << endl;
    LinkList a; LinkList b; Node* tmp;
    a.insert(1); a.insert(2); a.insert(3); a.insert(4);
    b.insert(10);  //b.insert(a.nthLast(1));
    a.display();
    b.display();
    tmp = a.IfIntersect(&b);
    if(tmp) cout<<" Intersection : " << tmp->data << endl;

    tmp = b.IfIntersect(&a);
    if (tmp) cout << " Intersection : " << tmp->data << endl;
    
    //6------------------------------------------------------------------
    cout << "Detecting Loops" << endl;
    l.clear(); 
    l.insert(1); l.insert(2); l.insert(3); l.insert(4); l.insert(5);
    l.display();
    //l.insert(l.nthLast(3));       //Crash on clear coz of loop
    cout <<"\nLoop : " << l.IsLoop() << endl;
    
    //7-----------------------------------------------------------------
    cout << "Sum List" <<endl;
    a.clear(); a.insert(9); a.insert(8); a.insert(7);
    b.clear(); b.insert(9); b.insert(9);
    LinkList *tempList = a.SumBackwardNo(&b);
    tempList->display();
    delete tempList;
}