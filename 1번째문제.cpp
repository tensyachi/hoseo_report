#include <stdio.h>

void main() {
	int amount[100] = { 0 };
	int item[100][100] = { 0 };
	int mod, id, cnt, io;

	do{
		printf("기능을 선택해 주세요.\n");
		printf("1)상품 재고를 입력한다.\n");
		printf("2)상품 재고를 확인한다.\n");
		printf("3)프로그램을 종료한다.\n>>");
		scanf("%d", &mod);

		if (mod == 1) {
			printf("\n--------------------------------------------------------\n");
			printf("상품의 ID를 입력해 주세요.(1~100) >>");
			scanf("%d", &id);
			printf("상품 종류의 수를 입력해 주세요.(1~100) >>");
			scanf("%d", &cnt);
			
			if (1 > cnt || cnt > 100 || 1 > cnt || cnt > 100) {amount[id] = 0;
				printf("잘못된 입력입니다.");
				printf("\n--------------------------------------------------------\n");
				continue;
			}

			amount[id] = cnt;

			printf("상품별 입고 수량을 입력해 주세요. >>");
			for (int i = 0; i < cnt; i++) {
				scanf("%d", &io);
				item[id][i] += io;
			}

			printf("상품별 판매 수량을 입력해 주세요. >>");
			for (int i = 0; i < cnt; i++) {
				scanf("%d", &io);
				if (io > item[id][i]) {
					printf("잘못된 입력입니다.");
				} else {
					item[id][i] -= io;
				}
			}
			printf("재고가 저장되었습니다.");
			printf("\n--------------------------------------------------------\n");
		}
		else if (mod == 2) {
			printf("\n--------------------------------------------------------\n");
			printf("상품의 ID를 입력해 주세요.(1~100) >>");
			scanf("%d", &id);
			cnt = amount[id];

			printf("상품 종류 : %d종\n", cnt);
			for (int i = 0; i < cnt; i++) {
				printf("상품%d 수량 : %d개\n", i, item[id][i]);
			}
			printf("\n--------------------------------------------------------\n");
		}
		else if (mod == 3) {
			printf("프로그램이 종료됩니다.");
		}
		else {
			printf("잘못된 입력입니다.");
		}
	} while (mod == 1 || mod == 2);
}