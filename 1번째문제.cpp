#include <stdio.h>

void main() {
	int amount[100] = { 0 };
	int item[100][100] = { 0 };
	int mod, id, cnt, io;

	do{
		printf("����� ������ �ּ���.\n");
		printf("1)��ǰ ��� �Է��Ѵ�.\n");
		printf("2)��ǰ ��� Ȯ���Ѵ�.\n");
		printf("3)���α׷��� �����Ѵ�.\n>>");
		scanf("%d", &mod);

		if (mod == 1) {
			printf("\n--------------------------------------------------------\n");
			printf("��ǰ�� ID�� �Է��� �ּ���.(1~100) >>");
			scanf("%d", &id);
			printf("��ǰ ������ ���� �Է��� �ּ���.(1~100) >>");
			scanf("%d", &cnt);
			
			if (1 > cnt || cnt > 100 || 1 > cnt || cnt > 100) {amount[id] = 0;
				printf("�߸��� �Է��Դϴ�.");
				printf("\n--------------------------------------------------------\n");
				continue;
			}

			amount[id] = cnt;

			printf("��ǰ�� �԰� ������ �Է��� �ּ���. >>");
			for (int i = 0; i < cnt; i++) {
				scanf("%d", &io);
				item[id][i] += io;
			}

			printf("��ǰ�� �Ǹ� ������ �Է��� �ּ���. >>");
			for (int i = 0; i < cnt; i++) {
				scanf("%d", &io);
				if (io > item[id][i]) {
					printf("�߸��� �Է��Դϴ�.");
				} else {
					item[id][i] -= io;
				}
			}
			printf("��� ����Ǿ����ϴ�.");
			printf("\n--------------------------------------------------------\n");
		}
		else if (mod == 2) {
			printf("\n--------------------------------------------------------\n");
			printf("��ǰ�� ID�� �Է��� �ּ���.(1~100) >>");
			scanf("%d", &id);
			cnt = amount[id];

			printf("��ǰ ���� : %d��\n", cnt);
			for (int i = 0; i < cnt; i++) {
				printf("��ǰ%d ���� : %d��\n", i, item[id][i]);
			}
			printf("\n--------------------------------------------------------\n");
		}
		else if (mod == 3) {
			printf("���α׷��� ����˴ϴ�.");
		}
		else {
			printf("�߸��� �Է��Դϴ�.");
		}
	} while (mod == 1 || mod == 2);
}