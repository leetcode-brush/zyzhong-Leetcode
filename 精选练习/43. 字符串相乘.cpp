class Solution {
public:
	string multiply(string num1, string num2) {
		string res = "";
        if (num1 == "0" || num2 == "0") return "0";
		//使用deque是因为出现进位时可以在队列前插入数据，效率比vector高，大小设为最小
		deque<int> vec(num1.size() + num2.size() - 1, 0);
		for (int i = 0; i < num1.size(); ++i) {
			for (int j = 0; j < num2.size(); ++j) {
				vec[i + j] += (num1[i] - '0') * (num2[j] - '0');//记录相乘结果
			}
		}
		//进位处理
		int addflag = 0;
		//倒序遍历，是因为最左边的值为最高位，最右边的值在最低位，进位运算要从低位开始
		for (int i = vec.size() - 1; i >= 0; --i) {
			int temp = vec[i] + addflag;//当前值加上进位值
			vec[i] = temp % 10;//当前值
			addflag = temp / 10;//进位值
		}
		//如果有进位，将进位加到队列头部
		while (addflag != 0) {
			int t = addflag % 10;
			vec.push_front(t);
			addflag /= 10;
		}
		for (auto c : vec) {
			ostringstream ss;
			ss << c;
			res += ss.str();
		}
		return res;
	}
};