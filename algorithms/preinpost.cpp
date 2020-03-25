//vector<node> btree;
//int create(int prelow, int preupper, int inlow, int inupper, int n) {
//	if(prelow > preupper) return -1;
//	node root;
//	root.x = pre[prelow];
//	int pos = find(in + 1, in + 1 + n, root.x) - in;
//	root.left = create(prelow + 1, prelow + pos - inlow, inlow, pos - 1, n);
//	root.right = create(prelow + pos - inlow + 1, prelow + pos - inlow + inupper - pos, pos + 1, inupper, n);
//	btree.push_back(root);
//	return btree.size() - 1;
//}