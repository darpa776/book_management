#include <stdio.h>
#include <string.h>
int start_view();//함수 선언
void insert();
void _delete();
void print();
void search();
void sort();
void finish();
int count = 0;//정렬함수에서 쓸 변수를 전역변수로 선언

struct BOOK//BOOK이라는 구조체 선언
{
	int number;
	char name[100];
	char writer[100];
	struct BOOK *next;
};

void main()
{
	struct BOOK head_node;
	head_node.next = NULL;//head_node의 다음 주소를 NULL로 초기화. head_node 안에는 쓰레기값. 
	while (1)//무한루프
	{
		int a;
		a = start_view();//start_view()함수의 결과를 a에 대입
		if (a == 1)
		{
			insert(&head_node);
		}
		else if (a == 2)
		{
			_delete(&head_node);//delete_node()는 이미 존재하는 시스템함수이기 때문에_사용해서 구분했음
		}
		else if (a == 3)
		{
			print(&head_node);
		}
		else if (a == 4)
		{
			search(&head_node);
		}
		else if (a == 5)
		{
			sort(&head_node);
		}
		else if (a == 6)
		{
			finish(&head_node);
			break;
		}
		else
		{
			printf("잘못 입력했습니다.\n");
		}
	}
}

int start_view()
{
	int num = 0;
	printf("\n도서관리 프로그램입니다.\n");
	printf("원하는 기능을 입력해주세요.\n");
	printf("1.추가 2.삭제 3.출력 4.탐색 5.정렬 6.종료: ");
	scanf_s("%d", &num);
	return num;//사용자가 입력한 숫자를 반환
}

void insert(struct BOOK * head_node)//삽입 함수.
{
	struct BOOK *new;
	new = (struct BOOK*)malloc(sizeof(struct BOOK));
	printf("책 번호를 입력해주세요 : ");
	scanf_s("%d", &new->number);
	printf("책 이름을 입력해주세요 : ");
	scanf_s("%s", new->name, 100);
	printf("책 저자를 입력해주세요 : ");
	scanf_s("%s", new->writer, 100);
	if (head_node->next == NULL)//입력하는 정보가 첫 자료일 경우
	{
		new->next = head_node->next;//head와 NULL사이에 입력
		head_node->next = new;
		count++;//자료의 개수 증가
		printf("입력이 완료되었습니다.\n");
		return;
	}
	else
	{
		for ( ; head_node->next != NULL; head_node = head_node->next)//자료의 끝까지 감(NULL앞까지)
		{
			if (new->number == head_node->next->number)//중복된 책번호가 존재할 경우
			{
				printf("중복된 자료가 존재합니다.\n자료를 저장하지 않습니다.\n");
				return;//함수종료
			}
		}//이동해 간 head_node의 다음이 NULL이면 for문을 나옴.
		new->next = head_node->next;//NULL앞에 자료를 저장
		head_node->next = new;
		count++;//자료의 개수 증가
		printf("입력이 완료되었습니다.\n");
	}
}

void _delete(struct BOOK* head_node)//삭제함수
{
	int k = 0;//사용자가 입력할 책번호
	printf("지울 자료의 책 번호를 입력하세요: ");
	scanf_s("%d", &k);
	if (head_node->next == NULL)//아무 자료도 없을때
	{
		printf("삭제할 자료가 없습니다.\n");
		return;//함수종료
	}
	for (; head_node != NULL; head_node = head_node->next)//자료의 끝까지 감
	{
		if (head_node->next->number == k)//삭제할 책번호를 찾았을 때
		{
			struct BOOK*delete_node = head_node->next;//head_node의 다음 노드를 delete_node라 지정
			head_node->next = head_node->next->next;//delete_node의 다음을 head_node의 다음으로 이어줌
			free(delete_node);//지울 노드의 동적할당 해제
			printf("삭제가 완료되었습니다.\n");
			count--;//자료의 개수 감소
			break;//for문을 나감
		}
	}
}

void print(struct BOOK* head_node)//출력함수
{
	if (head_node->next == NULL)//아무 자료도 없을때
	{
		printf("자료가 존재하지 않습니다.\n");
	}
	for (head_node = head_node->next; head_node != NULL; head_node = head_node->next)//자료의 끝까지 감
	{
		printf("책번호 : %d\n", head_node->number);//자료의 끝까지 head_node를 이동시키면서 다음의 내용들을 출력함
		printf("책이름 : %s\n", head_node->name);
		printf("책저자 : %s\n", head_node->writer);
	}

}

void search(struct BOOK * head_node)//탐색함수
{
	int j=0;
	int search_type;//탐색할 자료의 종류
	int search_number;//탐색할 자료의 책번호
	char search_name[100];//탐색할 자료의 책이름
	char search_author[100];//탐색할 자료의 저자

	if (head_node->next == NULL)//자료가 아무것도 없을 때
	{
		printf("자료가 존재하지 않습니다.\n");
		return;//함수종료
	}

	else
	{
		printf("1.책번호로 탐색. 2. 책이름으로 탐색. 3. 저자로 탐색. ");
		scanf_s("%d", &search_type);

		if (search_type == 1)
		{
			printf("탐색할 자료의 책번호를 입력하세요.");
			scanf_s("%d", &search_number);
			for (; head_node != NULL; head_node = head_node->next)//자료의 끝까지 head_node를 이동
			{
				if (head_node->number == search_number)//찾으려는 자료의 책번호와 이동한 head_node의 책번호가 같으면
				{
					printf("자료가 존재합니다.\n");
					printf("책번호 : %d\n", head_node->number);
					printf("책이름 : %s\n", head_node->name);
					printf("책저자 : %s\n", head_node->writer);
					printf("\n");//출력
				}
			}
			return;
		}

		if (search_type == 2)
		{
			printf("탐색할 자료의 책이름을 입력하세요.");
			scanf_s("%s", search_name, 100);

			for (; head_node != NULL; head_node = head_node->next)//자료의 끝까지 head_node를 이동
			{
				if (_stricmp(head_node->name, search_name) == 0)//스트링아이컴페어 함수
				{
					printf("자료가 존재합니다.\n");
					printf("책번호 : %d\n", head_node->number);
					printf("책이름 : %s\n", head_node->name);
					printf("책저자 : %s\n", head_node->writer);
					printf("\n");//출력
				}
			}
			return;
		}
			if (search_type == 3)
			{

				printf("탐색할 자료의 저자를 입력하세요.");
				scanf_s("%s", search_author, 100);
				for (; head_node != NULL; head_node = head_node->next)//자료의 끝까지 head_node를 이동
				{
					if (_stricmp(head_node->writer, search_author) == 0)//찾으려는 자료의 저자와 이동한 head_node의 저자가 같으면
					{
						printf("자료가 존재합니다.\n");
						printf("책번호 : %d\n", head_node->number);
						printf("책이름 : %s\n", head_node->name);
						printf("책저자 : %s\n", head_node->writer);
						printf("\n");//출력
						
					}
				}
				return;
			}
	}
}

void sort(struct BOOK * head_node)//정렬함수
{
	int i = 0;
	struct BOOK * temp = head_node->next;//head_node의 다음을 temp로 선언
	if (head_node->next == NULL)//자료가 없을 때
	{
		printf("정렬할 내용이 없습니다.\n");
	}
	else if (head_node->next->next == NULL)//자료가 하나 밖에 없을 때
	{
		printf("자료가 하나이므로 정렬하지 않습니다.\n");
	}
	else//자료가 두개 이상일 때
	{
		struct BOOK* start = head_node;//head_node를 start로 지정
		for (i = 0; i < (count - 1); i++)//아래의 for문을 자료의 개수-1 만큼 다시 돌려야 정렬이 완료됨.
		{
			for (head_node = start; temp->next != NULL; head_node = head_node->next)//head_node(start)부터 자료의 끝까지  head_node를 넘김
			{
				if (head_node->next->number > head_node->next->next->number)//자료의 책번호를 비교함
				{//앞에 있는 자료의 책번호가 더 클때=정렬을 해야할 때
					temp = head_node->next;//head_node의 다음 노드를 temp로 지정
					head_node->next = temp->next;
					temp->next = head_node->next->next;
					head_node->next->next = temp;//temp를 이용해 자료 두개를 서로 바꿈
				}
			}

		}
		printf("정렬이 완료되었습니다.\n");
	}
}

void finish(struct BOOK * head_node)//종료함수
{
	struct BOOK* temp = head_node->next;//head_node의 다음을 temp로 지정
	for (; temp != NULL;)//head_node의 다음이 NULL일 때까지(자료의 끝까지)
	{
		head_node = temp;//head_node를 다음 노드로 이동
		temp = head_node->next;//이동시킨 head_node의 다음을 temp로 지정
		free(head_node);//head_node동적할당 해제
	}
}