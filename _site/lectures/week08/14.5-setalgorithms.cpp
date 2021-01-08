#include<iostream>
using std::cout; using std::endl;
#include<set>
using std::set;
#include<vector>
using std::vector;
#include<iterator>
using std::ostream_iterator;
#include<algorithm>
using std::set_union; using std::set_intersection;
using std::set_difference;
using std::set_symmetric_difference;
using std::sort; using std::find;

int main (){
  // make iter once and reuse in the algorithms
  ostream_iterator<long> os_itr (cout, ",");
  
  // regular sets get sorted automatically!
  set<long> s1={5,4,2,3,1};
  set<long> s2={7,4,6,3,5};

  // generic algorithm find vs set method find
  set<long>::iterator iter;
  iter = find(s1.begin(), s1.end(), 5);
  iter = s1.find(5);

  cout << "Union:" << endl;
  set_union(s1.begin(), s1.end(),
	    s2.begin(), s2.end(),
	    os_itr);

  cout << '\n' << "Intersection:" << endl;
  set_intersection(s1.begin(), s1.end(),
		   s2.begin(), s2.end(),
		   os_itr);

  cout << "\n" << "Difference:" << endl;
  set_difference(s1.begin(), s1.end(),
		 s2.begin(), s2.end(),
		 os_itr);

  cout << '\n' << "Symmetric Difference:" << endl;
  set_symmetric_difference(s1.begin(), s1.end(),
			   s2.begin(), s2.end(),
			   os_itr);
  cout << endl;
  
  // works with other STL containers as well
  // repeated elements are interesting
  vector<long> v1 = {1,2,2,2,3,4};
  vector<long> v2 = {2,2,3,4,5,6};
  
  // must sort unsorted containers
  sort(v1.begin(), v1.end() );
  sort(v2.begin(), v2.end() );
  
  cout << "\nVectors with repeats"<<endl;
  cout << "Union:" << endl;
  set_union(v1.begin(), v1.end(),
	    v2.begin(), v2.end(),
	    os_itr);

  cout << '\n' << "Intersection:" << endl;
  set_intersection(v1.begin(), v1.end(),
		   v2.begin(), v2.end(),
		   os_itr);

  cout << "\n" << "Difference:" << endl;
  set_difference(v1.begin(), v1.end(),
		 v2.begin(), v2.end(),
		 os_itr);

  cout << '\n' << "Symmetric Difference:" << endl;
  set_symmetric_difference(v1.begin(), v1.end(),
			   v2.begin(), v2.end(),
			   os_itr);
  cout << endl;
}
