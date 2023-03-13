//
//  basic_hashing.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 30/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable = NULL;
int SIZE = 10;

struct node{
    int key;
    int value;
    struct node* next; //   체이닝 구현시 다음 값
};

struct bucket {
    struct node* head;
    int count;      // 버켓에 몇개의 값이 있는지
};

// 새로운 메모리를 할당하고 기본값을 세팅해주는 역할
struct node* createNode(int key, int value){
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;     // 유저가 만들고자 하는 키
    newNode->value = value; // 유저가 만들고자 하는 값
    newNode->next = NULL;
    
    return newNode;
}

// 해쉬 Function 구현
int hashFunction(int key){
    // key 값이 들어오면 몇번으로 들어가는지 로직을 설정한다.
    
    return key%SIZE;
}
void insert(int key, int value){
    int hashIndex = hashFunction(key);
    struct node *newNode = createNode(key,value);
    //내가 넣고자 하는 인덱스에 이미 값이 없는 경우
    if(hashTable[hashIndex].count == 0){
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count = 1;
    }
    //내가 넣고자 하는 인덱스에 이미 값이 있는 경우
    else{
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
        
    }
    return;
}
void remove1(int key){
    int hashIndex = hashFunction(key);
    struct node* node;
    struct node* trace = NULL;
    
    node = hashTable[hashIndex].head;
    if(node == NULL){
        printf("\n no key found");
        return;
    }
    // 삭제이후 체이닝된 값들을 다시 재정렬해주는 것이 필요함.
    while(node != NULL){
        //찾은 경우
        if(node->key == key){
            printf("yes kye found and remove : %d\n", key);
            // 지운값이 헤드인 경우(포인터를 바꾸어주는 부분)
            if(node == hashTable[hashIndex].head){
                hashTable[hashIndex].head = node->next;
            // 지운값이 헤드가 아닌경우
            }else{
                trace->next = node->next;
            }
            hashTable[hashIndex].count--;
            free(node);
            return ;
        }
        trace = node;
        node = node->next;
    }
    printf("no key found\n");
    return;
    
}
void search(int key){
    // 삭제처럼 trace 노드를 만들필요는 없음.
    
    int hashIndex = hashFunction(key);
    struct node* node = hashTable[hashIndex].head;
    
    if(node == NULL){
        printf("\nno key found");
        return;
    }
    while(node != NULL){
        // 찾았다의 상황
        
        if(node->key == key){
            printf("key found key = [%d] value =[%d]",node->key,node->value);
            break;
        }
        node = node->next;
    }
    printf("\nno key found");
    return;
    
}
void display(){
    struct node* horse;
    for(int i=0; i<SIZE; i++){
        horse = hashTable[i].head;
        printf("Bucket[%d] : ", i);
        while(horse != NULL){
//            printf("key found key = [%d] value =[%d]",horse->key,horse->value);
            printf("(key:%d, val:%d)", horse->key, horse->value);
            horse = horse->next;
        }
        printf("\n");
        
    }
    return;
}

int main(void){
    // Intuialize
    hashTable = (struct bucket*)malloc(SIZE *sizeof(struct bucket));
    
    insert(0,1);
    insert(1,10);
    insert(11,90);
    insert(21,64);
    insert(31,23);
    insert(6,25);
    insert(97,23);
    display();
    remove1(31);
    display();
    
    
}