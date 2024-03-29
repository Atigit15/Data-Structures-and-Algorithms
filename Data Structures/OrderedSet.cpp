#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

//can perform all operations performed by set + 2 additional
// find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.
//To find the first element k == 0.
// order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.

int main()
{
	ordered_set o_set;
    
	o_set.insert(5);
	o_set.insert(1);
	o_set.insert(2);

	// Finding the second smallest element in the set , using * because find_by_order returns an iterator
	cout << *(o_set.find_by_order(1))<< endl;

	// Finding the number of elements strictly less than k=4
	cout << o_set.order_of_key(4)<< endl;

	// Finding the count of elements less than or equal to 4 i.e. strictly less than 5 
	cout << o_set.order_of_key(5)<< endl;

	// Deleting 2 from the set if it exists
	if (o_set.find(2) != o_set.end())
		o_set.erase(o_set.find(2));

	// Now after deleting 2 from the set Finding the second smallest element in the set
	cout << *(o_set.find_by_order(1))<< endl;

	return 0;
}
