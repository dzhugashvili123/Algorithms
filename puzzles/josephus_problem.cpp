/*When there are n-people in a cirkle every (k-1)th person is eleminated circularly, who survives,ie the current guy is counted as well. The next round stats from killed guy+1
The answer is in the recurrence relation J(n, k) = ( J(n-1, k) + k) mod n where J(1, k) = 0
!!!!!!!This pertains to 0-based indexing.!!!!!!!
Think of it this way, let use assume 0, 1, 2, 3, 4, ..... n-1, ie problem of size n, and take k, then (k-1)th person will be killed and sword goes to kth person, the absolute position is k, and next round starts with kth-person at 0, 0 is his relative ordering and k is his absolute ordering. So, to get absolute position, we add k.
If J(n-1, k) is the relative position of final survivor, we add k and do mod n. J(1, k) is the relative position of the survivor in the final round, J(2, k) is the relative position in the penultimate round, we translate J(1, k) position to penultimate round postion by +k)modn. SImilary, we work backwards to find the absolute position.*/

#include<iostream>
#include<cstdlib>

int josephus_trials_survivor(int n, int k){

	int survivor = 0;
	for( int i=2; i<=n; i++){	//We already know J(1), we are calculating from J(2), all the way to J(n)
		survivor = (survivor + k) % i;
	}

	return survivor;
}

int main(int argc, char **argv){
	if( argc < 3)
		return -1;

	int n = std::stoi( argv[1]);
	int k = std::stoi( argv[2]);

	int final_survivor = josephus_trials_survivor(n, k);
	return final_survivor;
}
