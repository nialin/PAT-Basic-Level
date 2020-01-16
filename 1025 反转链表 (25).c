#include <stdio.h>

struct node {
	int data, next;
};

int list_reverse(struct node *nodes, int head, int k)
{
	int i, p, new_head, tmp_head;

	for(i = 0, p = head; i < k && p != -1; ++i, p = nodes[p].next)
		;

	if(i < k)
		return head;

	for(i = 0, new_head = -1, tmp_head = head; i < k; ++i) {
		p = tmp_head;
		tmp_head = nodes[tmp_head].next;

		nodes[p].next = new_head;
		new_head = p;
	}

	nodes[head].next = list_reverse(nodes, tmp_head, k);

	return new_head;
}

int main()
{
	int head, n, k, i, addr;
	struct node nodes[100000] = {{0}};

	scanf("%d%d%d", &head, &n, &k);

	for(i = 0; i < n; ++i) {
		scanf("%d", &addr);
		scanf("%d%d", &nodes[addr].data, &nodes[addr].next);
	}

	head = list_reverse(nodes, head, k);

	for(i = head; nodes[i].next != -1;i = nodes[i].next)
		printf("%05d %d %05d\n", i, nodes[i].data, nodes[i].next);

	printf("%05d %d -1\n", i, nodes[i].data);

	return 0;
}
