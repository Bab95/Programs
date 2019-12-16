#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct point {
	int x, y;
};
struct rect {
	point l, r;
};
void rearrangepoint(struct rect *r1) {
	int tmp;
	if (r1->l.x>r1->r.x) {
		//swap
		tmp = r1->l.x;
		r1->l.x = r1->r.x;
		r1->r.x = tmp;

		tmp = r1->l.y;
		r1->l.y = r1->r.y;
		r1->r.y = tmp;
	}
	if (r1->l.y<r1->r.y) {
		tmp = r1->l.y;
		r1->l.y = r1->r.y;
		r1->r.y = tmp;
	}
}
void swap_rectangles(struct rect *r1, struct rect *r2) {
	int x1 = r1->l.x;
	int y1 = r1->l.y;
	int x2 = r1->r.x;
	int y2 = r1->r.y;

	r1->l.x = r2->l.x;
	r1->l.y = r2->l.y;
	r1->r.x = r2->r.x;
	r1->r.y = r2->r.y;


	r2->l.x = x1;
	r2->l.y = y1;
	r2->r.x = x2;
	r2->r.y = y2;
}

void rearrangerectangles(struct rect *r1, struct rect *r2) {
	if (r1->l.x > r2->l.x) {
		swap_rectangles(r1, r2);
	}
}
bool overlap(struct rect *rect1, struct rect *rect2) {
	if (rect1->r.x <= rect2->l.x) {
		return false;
	}
	if (rect1->l.y <= rect2->r.y) {
		return false;
	}
	if (rect1->r.y >= rect2->l.y) {
		return false;
	}
	return true;
}
void printrect(struct rect r1){
	cout << "(" << r1.l.x << "," << r1.l.y << "), (" << r1.r.x << "," << r1.r.y << ")" << endl;
}
int main() {
	//code
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	rect r1, r2;
	while (t--) {
		cin >> r1.l.x >> r1.l.y >> r1.r.x >> r1.r.y;
		cin >> r2.l.x >> r2.l.y >> r2.r.x >> r2.r.y;
		rearrangepoint(&r1);
		rearrangepoint(&r2);
		rearrangerectangles(&r1, &r2);
		printrect(r1);
		printrect(r2);
		if (overlap(&r1, &r2)) {
			cout << "1" << endl;
		}
		else {
			cout << "0";
		}
	}
	return 0;
}
