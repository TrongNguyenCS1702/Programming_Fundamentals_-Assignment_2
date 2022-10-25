//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string input3);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////
char inttochar(int a) {
	return char(a + 65);
}
int chartoint(char a) {
	return (int)a - 48;
}
int dinhdanh(string a) {
	int l = a.size();
	if (a.substr(0, 3) == "VUA") return 1;
	else {
		for (int i = 1; i <= l - 4; i++) {
			string b = a.substr(i, 3);
			if (b == "THD") { return 2; break; }
		}
		return 0;
	}
}
/////////////////////////////////////////////////////////
string substep1(string m1) {
	string sub; unsigned long i = 0;
	while (i < m1.size()) {
		if (i == 0) {
			if (m1.substr(i, 2) == "00") sub = "0";
			else if (m1.substr(i, 2) == "01") sub = "1";
			else if (m1.substr(i, 2) == "10") sub = "2";
			else if (m1.substr(i, 2) == "11") sub = "3";
			i += 2;
		}
		else {
			if (m1.substr(i, 2) == "00") sub += "0";
			else if (m1.substr(i, 2) == "01") sub += "1";
			else if (m1.substr(i, 2) == "10") sub += "2";
			else if (m1.substr(i, 2) == "11") sub += "3";
			i += 2;
		}
		continue;
	}
	return sub;
}
string step1(string a) {
	int  j = 0, dem = 0, space = 0; string suba, b;
	for (unsigned long k = 0; k < a.size(); k++) if (a[k] == ' ') space += 1;
	if (space != 0) {
		for (unsigned long i = 0; i < a.size(); i++) {
			if (dem < space) {
				if (a[i] == ' ') {
					dem += 1;
					suba = a.substr(j, i - j);
					if (j == 0) b = substep1(suba); else b = b + " " + substep1(suba);
					j = i + 1;
					continue;
				}
			}
			else {
				suba = a.substr(j, a.size() - j);
				b = b + " " + substep1(suba);
				break;
			}
		}
		return b;
	}
	else {
		b = substep1(a);
		return b;
	}
	
}
char subStep2(string m2) {
	int l;
	if (m2.size() > 7) {
		if (m2.size() % 7 == 0) l = 7;
		else
		l = m2.size() % 7;
	}
	else l = m2.size();
	if (m2[0] == '0') return char(l + 68);
	else if (m2[0] == '1') return char(l + 75);
	else if (m2[0] == '2') {
		if (l == 1) return '#';
		else return char(l + 82);
	}
	else {
		switch (l) {
		case 1: return '@';
		case 2: return 'A';
		case 3: return 'S';
		case 4: return 'Z';
		case 5: return 'B';
		case 6: return 'C';
		case 7: return 'D';
		}
	}
	return '0';
}
string step2(string a) {
	int  j = 0, dem = 0, space = 0; string suba, b;
	for (unsigned long k = 0; k < a.size(); k++) if (a[k] == ' ') space += 1;
	if (space != 0) {
		for (unsigned long i = 0; i < a.size(); i++) {
			if (dem < space) {
				if (a[i] == ' ') {
					dem += 1;
					suba = a.substr(j, i - j);
					if (j == 0) b = subStep2(suba); else b += subStep2(suba);
					j = i + 1;
					continue;
				}
			}
			else {
				suba = a.substr(j, a.size() - j);
				b += subStep2(suba);
				return b;
			}
		}
		return "You can remove this return";
	}
	else {
		b = subStep2(a);
		return b;
	}
}
string subStep3(string a) {
	string b, rep;
	if (a[0] == '#') {
		a += a[a.size() - 1] + 1; 
		if (a[a.size() - 1] == '[') a[a.size() - 1] = 'A';
		b = a.substr(1, a.size());
	}
	else {
		b = a.substr(1, a.size() - 1);
		for (unsigned long i = 0; i < b.size(); i++) b[i] = a[a.size() - 1 - i];
	}
	return b;
}
string step3(string a) {
	int  j = 0, dem = 0, special = 0; string suba, b;
	for (unsigned long k = 0; k < a.size(); k++) if (a[k] == '#' || a[k] == '@') special += 1;
	if (special != 0) {
		for (unsigned long i = 0; i < a.size(); i++) {
			if (dem < special) {
				if (a[i] == '#' || a[i] == '@') {
					dem += 1;
					//suba = a.substr(j, i - j);
					if (j == 0) {
						suba = a.substr(j, i - j);
						b = suba;
					}
					else {
						suba = a.substr(j - 1, i - j + 1);
						b += subStep3(suba);
					}
					j = i + 1;
					continue;
				}
			}
			else {
				suba = a.substr(j - 1, a.size() - j + 1);
				if (suba == "")return b;
				else {
					b += subStep3(suba);
					return b;
				}
				
			}
		}
		return b;
	}
	else return a;
		
}
string step41(string a) {
	string b = a;
	if (b.size() % 2 == 1) {
		for (unsigned long i = 0; i < b.size(); i++) {
			b[i] = a[b.size() - 1 - i];
		}
	}
	else {
		for (unsigned long i = 0; i < b.size(); i++) {
			if (i % 2 == 0) b[i] = a[b.size() - 2 - i];
			else b[i] = a[b.size() - i];
		}
	}
	for (unsigned long j = 0; j < b.size(); j++) if (a[j] > b[j]) b[j] = a[j];
	return b;
}
string step42(string a) {
	int dem = 0, change;
	string b = a;
	for (unsigned long i = 0; i < a.size(); i++) {
		if (i % 3 == 0) {
			dem += 1;
			for (unsigned long j = i; j < a.size() - 1; j++) {
				b[j - dem + 1] = a[j + 1];
			}
		}
	}
	b = b.substr(0, b.size() - dem);
	if (b == "") return b;
	for (unsigned long k = 0; k < b.size() - 1; k++) {
		for (unsigned long h = k + 1; h < b.size(); h++) {
			if (b[k] > b[h]) {
				change = b[k];
				b[k] = b[h];
				b[h] = change;
			}
		}
	}
	return b;
}
/*---------------------------------------------*/
string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
	string a, b, c, d, result;
	int id = 0;
	for (int i = 0; i < NID ; i++) {
		if (dinhdanh(ID[i]) == 1) { id = 1; break; }
		else if (dinhdanh(ID[i]) == 2) { id = 2; break; } 
    }
	for (int j=0;j<N1;j++) {
		a = step1(input1[j]); 
		b = step2(a);	
		c = step3(b);
		if(c!="") {
			if (id == 1) d = step41(c);
			else if (id == 2) d = step42(c);
			else d = c;
			if (j == 0) result = d;
			else result += " " + d;
		}
		else {
			if (j == 0) result = c;
			else result += " " + c;
		}
	}
	return result;
}
////////////////////////////////////////////////////////
int decode(const string A, const string B)
{
	int la, lb, dem = 0;
	la = A.size();
	lb = B.size();
	for (int i = 0; i <= la - lb; i++) {
		if (A.substr(i, lb) == B)dem++;
	}
	return dem;
	return -1;
}
///////////////////////////////////////////////////////
string findRoute(const string input3)
{
	int x = 0, y = 0, dem = 0, j = 0, N, B, l, lmove, countmove, ch;
	string rep, subinp, route;

	for (unsigned long i = 0; i < input3.size(); i++) {
		if (dem < 2) {
			if (input3[i] == ' ') {
				dem += 1;
				subinp = input3.substr(j, i - j);
				if (dem == 1) N = stoi(subinp); else B = stoi(subinp);
				j = i + 1;
				continue;
			}
		}
		else {
			subinp = input3.substr(j, input3.size() - j);
			rep = subinp;
			break;
		}
	}
	l = subinp.size();
	/*------------------------------*/
	if (B > 0) {
		while (B >= l) B -= l;
	}
	else if (B < 0) {
		while (B <= -l) B += l;
	}
	/*-----------------------------*/
	if (B > 0) lmove = abs(l - B); else lmove = abs(l + B);
	if (B > 0) {
		for (int i = 0; i < l; i++) {
			countmove = i + lmove;
			if (countmove > l - 1) countmove -= l;
			rep[i] = subinp[countmove];
		}
	}
	else if (B < 0) {
		for (int i = 0; i < l; i++) {
			countmove = i - B;
			if (countmove > l - 1) countmove -= l;
			rep[i] = subinp[countmove];
		}
	}
	for (int i = 0; i < l; i++) {
		ch = abs(N - 2 * i) % 4;
		switch (ch) {
		case 1: {
			if (rep[i] == 'U') { rep[i] = 'D'; break; }
			if (rep[i] == 'D') { rep[i] = 'L'; break; }
			if (rep[i] == 'L') { rep[i] = 'R'; break; }
			if (rep[i] == 'R') { rep[i] = 'U'; break; }
		}
		case 2: {
			if (rep[i] == 'U') { rep[i] = 'L'; break; }
			if (rep[i] == 'D') { rep[i] = 'R'; break; }
			if (rep[i] == 'L') { rep[i] = 'U'; break; }
			if (rep[i] == 'R') { rep[i] = 'D'; break; }
		}
		case 3: {
			if (rep[i] == 'U') { rep[i] = 'R'; break; }
			if (rep[i] == 'D') { rep[i] = 'U'; break; }
			if (rep[i] == 'L') { rep[i] = 'D'; break; }
			if (rep[i] == 'R') { rep[i] = 'L'; break; }
		}
		}
	}
	for (int i = 0; i < l; i++) {
		if (rep[i] == 'U')y += 1;
		if (rep[i] == 'D')y -= 1;
		if (rep[i] == 'L')x -= 1;
		if (rep[i] == 'R')x += 1;
	}
	route = '(' + to_string(x) + ',' + to_string(y) + ')';
	return route;
}
//////////////////////////////////////////////////////
string findBetrayals(const string input5[], const int N5)
{
	string a, result;
	int arr[26] = { 0 };
	int spacenum, Max, SndMax, ThMax, iMax, iSndMax, iThMax, runMax, irunMax;
	for (int i = 0; i < N5; i++) {
		a = input5[i];
		for (int l = 0; l < 6; l++) {
			spacenum = a[l] - 'A';
			arr[spacenum] += (6 - l);
		}
	}
	Max = arr[0]; SndMax = arr[1]; ThMax = arr[2]; iMax = 0; iSndMax = 1; iThMax = 2;
	if (Max < SndMax) {
		swap(Max, SndMax); swap(iMax, iSndMax);
	}
	if (ThMax > Max) {
		swap(Max, ThMax); swap(iMax, iThMax);
	}
	if (ThMax > SndMax) {
		swap(ThMax, SndMax); swap(iThMax, iSndMax);
	}
	/////////
	if (Max == SndMax) {
		if (iMax > iSndMax) {
			swap(iMax, iSndMax);
		}
	}
	if (SndMax == ThMax) {
		if (iSndMax > iThMax) {
			swap(iSndMax, iThMax);
		}
	}

	for (int k = 0; k <= 22; k++) {
		runMax = arr[k + 3]; irunMax = k + 3;
		if (runMax > Max) {
			ThMax = SndMax; iThMax = iSndMax;
			SndMax = Max; iSndMax = iMax;
			Max = runMax; iMax = irunMax;
		}
		else {
			if (runMax > SndMax) {
				ThMax = SndMax; iThMax = iSndMax;
				SndMax = runMax; iSndMax = irunMax;
			}
			else {
				if (runMax > ThMax) {
					ThMax = runMax; iThMax = irunMax;
				}
			}
		}
		/////////////
		if (Max == SndMax) {
			if (iMax > iSndMax) {
				swap(iMax, iSndMax);
			}
		}
		if (SndMax == ThMax) {
			if (iSndMax > iThMax) {
				swap(iSndMax, iThMax);
			}
		}
		if (ThMax == runMax) {
			if (iThMax > irunMax) swap(iThMax, irunMax);
		}
	}

	result = inttochar(iMax);
	result = result + inttochar(iSndMax) + inttochar(iThMax);
	return result;
}
//////////////////////////////////////////////////////
string decodeVfunction(const string A, const string B)
{
	string result = "";
	int countA = 0, countB = 0, plus, lA = A.size(), lB = B.size();
	for (int i = 0; i < lA; i++) if (A[i] == 'V') countA += 1;
	for (int i = 0; i < lB; i++) if (B[i] == 'V') countB += 1;
	plus = countA * countB;
	for (int i = 0; i < plus; i++) result += "V(";
	result += '0';
	for (int i = 0; i < plus; i++) result += ")";
	return result;
}
//////////////////////////////////////////////////////
bool diffArrAtk(int a[], int b[]) {
	string stra = "1111111111", strb = "";
	for (int i = 0; i < 10; i++)
		if (a[i] != b[i]) strb += '0'; else strb += '1';
	if (stra == strb) return true; else return false;
}
/*----------------------*/
int attack(const string input6[])
{
	string a, lineMax0 = "", lineMax1 = "";
	int arr0[10] = { 0 }, arr1[10] = { 0 }, arr2[10] = { 0 }, blankarr[10] = { 0 };
	int max0, max1;
	for (int i = 0; i < 10; i++) {
		a = input6[i];
		for (int j = 0; j < 10; j++) {
			if (a[j] == '0') arr0[i] += 1;
			if (a[j] == '1') arr1[i] += 1;
			if (a[j] == '2') arr2[i] += 1;
		}
	}

	max0 = arr0[0];
	for (int i = 1; i < 10; i++)
		if (max0 < arr0[i]) max0 = arr0[i];

	for (int i = 0; i < 10; i++)
		if (arr0[i] == max0)  lineMax0 += char(i + 48);

	max1 = arr1[0];
	for (int i = 1; i < 10; i++)
		if (max1 < arr1[i]) max1 = arr1[i];

	for (int i = 0; i < 10; i++)
		if (arr1[i] == max1)  lineMax1 += char(i + 48);
	/*-------------------------------------*/
	if (   ((diffArrAtk(arr0, blankarr) == 1) && (diffArrAtk(arr1, blankarr) == 1))
		|| ((diffArrAtk(arr1, blankarr) == 1) && (diffArrAtk(arr2, blankarr) == 1))
		|| ((diffArrAtk(arr2, blankarr) == 1) && (diffArrAtk(arr0, blankarr) == 1))
	)
		return 9;
	if ((diffArrAtk(arr2, blankarr) == 1) || (diffArrAtk(arr1, blankarr) == 1))
		return chartoint(lineMax0[lineMax0.size() - 1]);
	if ((diffArrAtk(arr0, blankarr) == 1))
		return chartoint(lineMax1[lineMax1.size() - 1]);
	/*------------------*/
	string test = "";
	for (int i = 0; i < 10; i++) {
		if (arr2[i] != 0) test += '1'; else test += '0';
	}
	if (test == "1111111111") return -1;
	
		
	string result = "0123456789";
	for (int i = 0; i < 10 ; i++) 
		if (arr2[i] != 0) result[i] = 'n';
	for(unsigned long i=0;i<result.size();i++)
		if (result[i] == 'n') {
			result.erase(i, 1);
				i--;
		}

	int maxR = arr0[chartoint(result[0])];
	for (unsigned long i = 1; i < result.size(); i++) {
		if (maxR < arr0[chartoint(result[i])]) maxR = arr0[chartoint(result[i])];
	}
	for (unsigned long i = 0; i < result.size(); i++) {
		if (arr0[chartoint(result[i])] != maxR)
		{
			result.erase(i, 1);
			i--;
		}
	}
	return chartoint(result[result.size() - 1]);
}
//////////////////////////////////////////////////////
void arr1dtoarr2d( int arr1d[],long long int arr2d[100][100],int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr2d[i][j] = arr1d[(i * N + j)];
		}
	}
}
void stringtoarr1d( string input, int arr[], int N ) {
	int space = 0; string suba;
	int m = 0, dem = 0;
	for (unsigned long n = 0; n < input.size(); n++) if (input[n] == ' ') space += 1;
	for (unsigned long l = 0; l < input.size(); l++) {// dua gia tri vao mang 1
		if (dem < space) {
			if (input[l] == ' ') {
				dem += 1;
				suba = input.substr(m, l - m);
				arr[dem - 1] = stoi(suba);
				m = l + 1;
				continue;
			}
		}
		else {
			suba = input.substr(m, input.size() - m);
			arr[(N * N) - 1] = stoi(suba);
			break;
		}
	}
}
void Plusarr(long long int arr1[100][100], long long int arr2[100][100], long long int resArr[100][100], int N)
{
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++)
		{
			resArr[i][k] = 0;
			for (int j = 0; j < N; j++)
				resArr[i][k] = resArr[i][k] + arr1[i][j] * arr2[j][k];
		}
	}		
}
void changearr(long long int arr1[100][100], long long int arr2[100][100], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr2[i][j] = arr1[i][j];
		}
	}
}
/*-----------------------------------------------*/
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
	string subinp;
	int N, V, i, j, dem = 0,m=0;

	for (unsigned long l = 0; l < input7Str.size(); l++) {
		if (dem < 3) {
			if (input7Str[l] == ' ') {
				dem += 1;
				subinp = input7Str.substr(m, l - m);
				if (dem == 1) N = stoi(subinp);
				else if (dem == 2) V = stoi(subinp);
				else i = stoi(subinp);
				m = l + 1;
				continue;
			}
		}
		else {
			subinp = input7Str.substr(m, input7Str.size() - m);
			j = stoi(subinp);
			break;
		}
	}

	int arr1[10000], arr2[10000];
	stringtoarr1d(input7Matrix[0], arr1,N);
	stringtoarr1d(input7Matrix[1], arr2, N);

	long long int arr2dA[100][100], arr2dB[100][100];
	arr1dtoarr2d(arr1, arr2dA, N);
	arr1dtoarr2d(arr2, arr2dB, N);
	long long int resArr[100][100];
	Plusarr(arr2dA, arr2dB, resArr, N);
	for (int l = 2; l < k; l++) {
		changearr(resArr, arr2dA, N);
		stringtoarr1d(input7Matrix[l], arr2, N);
		arr1dtoarr2d(arr2, arr2dB, N);
		Plusarr(arr2dA, arr2dB, resArr, N);
	}
	int R;
	if (resArr[i][j] >= 0) {
		R = resArr[i][j] % V;
		return R;
	}
	else {
		R = (resArr[i][j]*(-1)) % V;
		return R*(-1);
	}

	return -1;
}
///////////////////////////////////////////////////////
#endif 
