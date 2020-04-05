#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

int main(){
    Node * head = NULL; // Node 구조체의 포인터 변수를 선언하고 Null로 초기화
    Node * tail = NULL;
    Node * cur = NULL;
    
    Node * newNode = NULL; // 우선 NewNode라는 구조체의 포인터 변수도 NULL로 초기화..
    int readData;
    
    // Scanning Data ///
    while(1){
        printf("자연수 입력: ");
        scanf("%d", &readData);
        if(readData<1){
            break;
        }
        //노드의 동적 추가 과정
        //새로운 노드를 먼저 추가하자.(힙에 할당)
        newNode = (Node*)malloc(sizeof(Node)); // malloc은 메모리를 힙에 동적할당해주는 함수임,
        newNode->data = readData;
        newNode->next = NULL;
        
        if(head == NULL){ //아직 헤드가 포인팅하는 Node 구조체가 없으면
            head = newNode; //newNode라는 노드 구조체가 헤드가 우선 된다.
        }
        else{ //만약 헤드가 Null ptr 가 아니라면, 즉, 이미 헤드가 있다면,
            tail->next = newNode;
        }
        tail = newNode;
    }
    printf("\n");
    
    //입력받은 데이터의 출력 과정
    printf("입력 받은 데이터의 전체 출력! \n");
    if(head == NULL){
        printf("There's nothing to save\n");
    }
    else{
        cur = head;
        printf("%d ", cur->data);
        while(cur->next != NULL){
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }
    printf("\n\n");
    
    // Memory 해제 과정
    if(head == NULL){
        return 0; // 해제할 노드가 존재 하지 않는다.
    }
    else{ //이렇게 삭제할 노드를 새로 delNode 포인터 변수에 받는 이유는, 받은 Node를 메모리 해제하기 위함
        Node * delNode = head;
        Node * delNextNode = head->next;
        
        printf("%d 을 삭제합니다.\n", delNode->data);
        free(delNode);
        
        while(delNextNode != NULL){
            delNode = delNextNode;
            delNextNode = delNextNode->next;
            
            printf("%d를 삭제합니다.\n", delNode->data);
            free(delNode);
        }
    }
    
    return 0;
}
