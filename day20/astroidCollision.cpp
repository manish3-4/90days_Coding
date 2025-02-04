//leetcode-735

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
    vector<int> st;
	for (auto element : arr) {

	if (element >= 0)
		st.push_back(element);

	else {
		
		while (st.size() > 0 && st.back() >= 0
			&& abs(element) > st.back())
		st.pop_back();

		
		if (st.size() > 0 && st.back() >= 0
			&& st.back() == abs(element))
		st.pop_back();

		
		else if (st.size() == 0 || st.back() < 0)
		st.push_back(element);
	}
	}
	return st;
    }
};