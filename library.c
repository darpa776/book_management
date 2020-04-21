#include <stdio.h>
#include <string.h>
int start_view();//�Լ� ����
void insert();
void _delete();
void print();
void search();
void sort();
void finish();
int count = 0;//�����Լ����� �� ������ ���������� ����

struct BOOK//BOOK�̶�� ����ü ����
{
	int number;
	char name[100];
	char writer[100];
	struct BOOK *next;
};

void main()
{
	struct BOOK head_node;
	head_node.next = NULL;//head_node�� ���� �ּҸ� NULL�� �ʱ�ȭ. head_node �ȿ��� �����Ⱚ. 
	while (1)//���ѷ���
	{
		int a;
		a = start_view();//start_view()�Լ��� ����� a�� ����
		if (a == 1)
		{
			insert(&head_node);
		}
		else if (a == 2)
		{
			_delete(&head_node);//delete_node()�� �̹� �����ϴ� �ý����Լ��̱� ������_����ؼ� ��������
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
			printf("�߸� �Է��߽��ϴ�.\n");
		}
	}
}

int start_view()
{
	int num = 0;
	printf("\n�������� ���α׷��Դϴ�.\n");
	printf("���ϴ� ����� �Է����ּ���.\n");
	printf("1.�߰� 2.���� 3.��� 4.Ž�� 5.���� 6.����: ");
	scanf_s("%d", &num);
	return num;//����ڰ� �Է��� ���ڸ� ��ȯ
}

void insert(struct BOOK * head_node)//���� �Լ�.
{
	struct BOOK *new;
	new = (struct BOOK*)malloc(sizeof(struct BOOK));
	printf("å ��ȣ�� �Է����ּ��� : ");
	scanf_s("%d", &new->number);
	printf("å �̸��� �Է����ּ��� : ");
	scanf_s("%s", new->name, 100);
	printf("å ���ڸ� �Է����ּ��� : ");
	scanf_s("%s", new->writer, 100);
	if (head_node->next == NULL)//�Է��ϴ� ������ ù �ڷ��� ���
	{
		new->next = head_node->next;//head�� NULL���̿� �Է�
		head_node->next = new;
		count++;//�ڷ��� ���� ����
		printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
		return;
	}
	else
	{
		for ( ; head_node->next != NULL; head_node = head_node->next)//�ڷ��� ������ ��(NULL�ձ���)
		{
			if (new->number == head_node->next->number)//�ߺ��� å��ȣ�� ������ ���
			{
				printf("�ߺ��� �ڷᰡ �����մϴ�.\n�ڷḦ �������� �ʽ��ϴ�.\n");
				return;//�Լ�����
			}
		}//�̵��� �� head_node�� ������ NULL�̸� for���� ����.
		new->next = head_node->next;//NULL�տ� �ڷḦ ����
		head_node->next = new;
		count++;//�ڷ��� ���� ����
		printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
	}
}

void _delete(struct BOOK* head_node)//�����Լ�
{
	int k = 0;//����ڰ� �Է��� å��ȣ
	printf("���� �ڷ��� å ��ȣ�� �Է��ϼ���: ");
	scanf_s("%d", &k);
	if (head_node->next == NULL)//�ƹ� �ڷᵵ ������
	{
		printf("������ �ڷᰡ �����ϴ�.\n");
		return;//�Լ�����
	}
	for (; head_node != NULL; head_node = head_node->next)//�ڷ��� ������ ��
	{
		if (head_node->next->number == k)//������ å��ȣ�� ã���� ��
		{
			struct BOOK*delete_node = head_node->next;//head_node�� ���� ��带 delete_node�� ����
			head_node->next = head_node->next->next;//delete_node�� ������ head_node�� �������� �̾���
			free(delete_node);//���� ����� �����Ҵ� ����
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
			count--;//�ڷ��� ���� ����
			break;//for���� ����
		}
	}
}

void print(struct BOOK* head_node)//����Լ�
{
	if (head_node->next == NULL)//�ƹ� �ڷᵵ ������
	{
		printf("�ڷᰡ �������� �ʽ��ϴ�.\n");
	}
	for (head_node = head_node->next; head_node != NULL; head_node = head_node->next)//�ڷ��� ������ ��
	{
		printf("å��ȣ : %d\n", head_node->number);//�ڷ��� ������ head_node�� �̵���Ű�鼭 ������ ������� �����
		printf("å�̸� : %s\n", head_node->name);
		printf("å���� : %s\n", head_node->writer);
	}

}

void search(struct BOOK * head_node)//Ž���Լ�
{
	int j=0;
	int search_type;//Ž���� �ڷ��� ����
	int search_number;//Ž���� �ڷ��� å��ȣ
	char search_name[100];//Ž���� �ڷ��� å�̸�
	char search_author[100];//Ž���� �ڷ��� ����

	if (head_node->next == NULL)//�ڷᰡ �ƹ��͵� ���� ��
	{
		printf("�ڷᰡ �������� �ʽ��ϴ�.\n");
		return;//�Լ�����
	}

	else
	{
		printf("1.å��ȣ�� Ž��. 2. å�̸����� Ž��. 3. ���ڷ� Ž��. ");
		scanf_s("%d", &search_type);

		if (search_type == 1)
		{
			printf("Ž���� �ڷ��� å��ȣ�� �Է��ϼ���.");
			scanf_s("%d", &search_number);
			for (; head_node != NULL; head_node = head_node->next)//�ڷ��� ������ head_node�� �̵�
			{
				if (head_node->number == search_number)//ã������ �ڷ��� å��ȣ�� �̵��� head_node�� å��ȣ�� ������
				{
					printf("�ڷᰡ �����մϴ�.\n");
					printf("å��ȣ : %d\n", head_node->number);
					printf("å�̸� : %s\n", head_node->name);
					printf("å���� : %s\n", head_node->writer);
					printf("\n");//���
				}
			}
			return;
		}

		if (search_type == 2)
		{
			printf("Ž���� �ڷ��� å�̸��� �Է��ϼ���.");
			scanf_s("%s", search_name, 100);

			for (; head_node != NULL; head_node = head_node->next)//�ڷ��� ������ head_node�� �̵�
			{
				if (_stricmp(head_node->name, search_name) == 0)//��Ʈ����������� �Լ�
				{
					printf("�ڷᰡ �����մϴ�.\n");
					printf("å��ȣ : %d\n", head_node->number);
					printf("å�̸� : %s\n", head_node->name);
					printf("å���� : %s\n", head_node->writer);
					printf("\n");//���
				}
			}
			return;
		}
			if (search_type == 3)
			{

				printf("Ž���� �ڷ��� ���ڸ� �Է��ϼ���.");
				scanf_s("%s", search_author, 100);
				for (; head_node != NULL; head_node = head_node->next)//�ڷ��� ������ head_node�� �̵�
				{
					if (_stricmp(head_node->writer, search_author) == 0)//ã������ �ڷ��� ���ڿ� �̵��� head_node�� ���ڰ� ������
					{
						printf("�ڷᰡ �����մϴ�.\n");
						printf("å��ȣ : %d\n", head_node->number);
						printf("å�̸� : %s\n", head_node->name);
						printf("å���� : %s\n", head_node->writer);
						printf("\n");//���
						
					}
				}
				return;
			}
	}
}

void sort(struct BOOK * head_node)//�����Լ�
{
	int i = 0;
	struct BOOK * temp = head_node->next;//head_node�� ������ temp�� ����
	if (head_node->next == NULL)//�ڷᰡ ���� ��
	{
		printf("������ ������ �����ϴ�.\n");
	}
	else if (head_node->next->next == NULL)//�ڷᰡ �ϳ� �ۿ� ���� ��
	{
		printf("�ڷᰡ �ϳ��̹Ƿ� �������� �ʽ��ϴ�.\n");
	}
	else//�ڷᰡ �ΰ� �̻��� ��
	{
		struct BOOK* start = head_node;//head_node�� start�� ����
		for (i = 0; i < (count - 1); i++)//�Ʒ��� for���� �ڷ��� ����-1 ��ŭ �ٽ� ������ ������ �Ϸ��.
		{
			for (head_node = start; temp->next != NULL; head_node = head_node->next)//head_node(start)���� �ڷ��� ������  head_node�� �ѱ�
			{
				if (head_node->next->number > head_node->next->next->number)//�ڷ��� å��ȣ�� ����
				{//�տ� �ִ� �ڷ��� å��ȣ�� �� Ŭ��=������ �ؾ��� ��
					temp = head_node->next;//head_node�� ���� ��带 temp�� ����
					head_node->next = temp->next;
					temp->next = head_node->next->next;
					head_node->next->next = temp;//temp�� �̿��� �ڷ� �ΰ��� ���� �ٲ�
				}
			}

		}
		printf("������ �Ϸ�Ǿ����ϴ�.\n");
	}
}

void finish(struct BOOK * head_node)//�����Լ�
{
	struct BOOK* temp = head_node->next;//head_node�� ������ temp�� ����
	for (; temp != NULL;)//head_node�� ������ NULL�� ������(�ڷ��� ������)
	{
		head_node = temp;//head_node�� ���� ���� �̵�
		temp = head_node->next;//�̵���Ų head_node�� ������ temp�� ����
		free(head_node);//head_node�����Ҵ� ����
	}
}