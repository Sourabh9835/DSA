//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include <vector>
class Solution {
    private:
    /*
    bool checkPalindrome(vector<int> arr){
        int n = arr.size();
        int s = 0;
        int e = n-1;
        
        while(s<=e){
            if(arr[s] != arr[e])
            return 0;
            
        s++;
        e--;
        
        }
        
        return 1;
    }
    */
    
    
    //finding middle
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    
    //reversing the list after middle
    Node* reverseList(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        
        /*
        vector<int> arr;
        
        Node* temp = head;
        while( temp != NULL){
            arr.push_back(temp -> data);
            temp = temp -> next;
        }
        return checkPalindrome(arr);
        
        */
        
        //if list is empty or only one element is present
        if(head == NULL || head -> next == NULL)
        return true;
        
        
        //step 1: find middle of list
        Node* middle = getMid(head);
        
        //step 2: reverse the list from middle
        Node* temp = middle -> next;
        middle -> next = reverseList(temp);
        
        //step 3: compare two halves if it is palindrome or not
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while(head2 != NULL){
            if(head1 -> data != head2 -> data){
                return false;
            }
            
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        
        //step 4 : repeating the step 2 so that list is not manipulated
        temp = middle -> next;
        middle -> next = reverseList(temp);
        
        return true;
    }
};


//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends