#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 105


using namespace std;

int row, column, n;

bool Left[MAX+7];
bool Right[MAX+7];

int left_weight;
int right_weight;

int main()
{
	int tc, t = 0, i, j, k, m, x, y, z, a, b, c, value, l, d, mx;
	char ch;
	bool flag;

	scanf("%d", &tc);

	for(t = 1; t <= tc; t++)
	{
		scanf("%d", &n);
		memset(Left, 0, sizeof Left);
		memset(Right, 0, sizeof Right);

		left_weight = right_weight = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			if(!Left[a] && !Right[b])
			{
				Left[a] = Right[b] = true;
				left_weight += c;
			}
			else
			{
				Right[a] = Left[b] = true;
				right_weight += c;
			}
		}

		printf("Case %d: %d\n", t, min(left_weight, right_weight));
	}

	return 0;
}
