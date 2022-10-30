#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node* prev; // 이전 노드 
    struct node* next; // 다음 노드 
}node;

void print(node*); // linked list print
node* deleteAll(node*, node**);

int main(void){
    int cnt; // num of testcase

    scanf("%d", &cnt);
    getchar(); // 입력 버퍼 비우기 

    while(cnt--){
        char ch; // input password

        node * n;
        node * tmp;
 
        node * head = (node*)malloc(sizeof(node));
        node * corsor = head;
        head->data = '!';
        head->next = NULL; 
        head->prev = NULL;

        while(1){
            scanf("%c", &ch); // 공백 입력 시 white space를 구분자로 인식
            if(ch == '\n')
                break;
            switch (ch)
            {
            case '-':
                if(corsor->prev == NULL) continue;

                tmp = (node*)malloc(sizeof(node));
                tmp = corsor;
                corsor = tmp->prev;

                if(tmp->next == NULL){
                    tmp->prev->next = NULL;
                }else{
                    tmp->prev->next = tmp->next;
                    tmp->next->prev = tmp->prev;
                }
                free(tmp);
                break;
            case '<':
                if(corsor->prev)
                    corsor = corsor->prev;
                break;
            case '>':
                if(corsor->next)
                    corsor = corsor->next;
                break;
            case 'a' ... 'z':
            case 'A' ... 'Z':
            case 48 ... 57:
                n = (node*)malloc(sizeof(node));
                n->data = ch; 
                n->prev = corsor;
                
                if(corsor->next == NULL){ // 커서가 마지막 노드를 가리키는 경우
                    n->next = NULL;
                }else{
                    corsor->next->prev = n;
                    n->next = corsor->next;
                }
                corsor->next = n;
                corsor = corsor->next;
                //printf("%c", corsor->data);
                break;
            default:
                break;
            }
        }
        print(head);
    }
    return 0;
}
void print(node*head){

    node * tmp = head->next;

    if(head->next == NULL){printf("emptylist"); return;}

    while(tmp){
        printf("%c", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
