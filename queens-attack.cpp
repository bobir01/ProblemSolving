#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int row, int col, vector<vector<int>> arr) {
    
vector<int> 
chap={row, 1}, 
chaptep={n, 1}, 
tep={n, col}, 
tepong={n, n}, 
ong={row, n}, 
ongpas={1, n}, 
pas={1, col}, 
paschap={1, 1};
if(n-row>col-1)chaptep={row+col-1, 1};
else chaptep={n, col-(n-row)};
if(n-row>n-col)tepong={row+n-col,n};
else tepong={n, col+n-row};
if(row-1>n-col)ongpas={row-(n-col),n};
else ongpas={1, col+row-1};
if(row-1>col-1)paschap={row-(col-1),1};
else paschap={1, col-(row-1)};
int chap1=0, chaptep1=0, tep1=0, tepong1=0, ong1=0, ongpas1=0, pas1=0, paschap1=0;

for(int i=0; k!=0 && i<arr.size(); i++){
    //////////////////////////////CHAP///////////////////////////////////////////
    if(chap1==0 && row==arr[i][0] && col>arr[i][1]){chap=arr[i];chap[1]+=1; chap1++;}
    if(chap1==1 && row==arr[i][0] && col>arr[i][1])if(chap[1]<arr[i][1]){chap=arr[i];chap[1]+=1;}
     //////////////////////////////CHAPTEP///////////////////////////////////////////
     if(chaptep1==0 && arr[i][0]-row==col-arr[i][1]&& arr[i][0]>row){chaptep=arr[i];chaptep[0]-=1; chaptep[1]+=1; chaptep1++;}
     if(chaptep1==1 && arr[i][0]-row==col-arr[i][1]&& arr[i][0]>row)if(arr[i][0]<chaptep[0]){chaptep=arr[i];chaptep[0]-=1; chaptep[1]+=1;}
     //////////////////////////////TEP///////////////////////////////////////////
     if(tep1==0&& arr[i][0]>row && col==arr[i][1]){tep1++; tep=arr[i];tep[0]-=1;}
     if(tep1==1&& arr[i][0]>row && col==arr[i][1])if(arr[i][0]>tep[0]){tep=arr[i];tep[0]-=1;}
     //////////////////////////////TEPONG///////////////////////////////////////////
     if(tepong1==0 && arr[i][0]-row==arr[i][1]-col && arr[i][1]>col){tepong1++; tepong=arr[i];tepong[0]-=1; tepong[1]-=1;}
     if(tepong1==1 && arr[i][0]-row==arr[i][1]-col && arr[i][1]>col)if(arr[i][0]<tepong[0]){tepong=arr[i];tepong[0]-=1; tepong[1]-=1;}
     //////////////////////////////ONG///////////////////////////////////////////
     if(ong1==0 && row==arr[i][0]&& arr[i][1]>col){ong1++; ong=arr[i];ong[1]-=1;}
     if(ong1==1 && row==arr[i][0]&& arr[i][1]>col)if(arr[i][1]<ong[1]){ong=arr[i];ong[1]-=1;}
     //////////////////////////////ONGPAS///////////////////////////////////////////
     if(ongpas1==0 && row-arr[i][0]==arr[i][1]-col && col<arr[i][1]){ongpas1++; ongpas=arr[i];ongpas[0]+=1; ongpas[1]-=1;}
     if(ongpas1==1 && row-arr[i][0]==arr[i][1]-col && col<arr[i][1])if(ongpas[1]>arr[i][1]){ongpas=arr[i];ongpas[0]+=1; ongpas[1]-=1;}
     //////////////////////////////PAS///////////////////////////////////////////
     if(pas1==0 && arr[i][1]==col && row>arr[i][0]){pas1++; pas=arr[i];pas[0]+=1; }
     if(pas1==1 && arr[i][1]==col && row>arr[i][0])if(arr[i][0]>pas[0]){pas=arr[i];pas[0]+=1;}
     //////////////////////////////PASCHAP///////////////////////////////////////////
     if(paschap1==0 && row-arr[i][0]==col-arr[i][1] && arr[i][0]<row){paschap=arr[i];paschap1++;paschap[0]+=1; paschap[1]+=1;}
     if(paschap1==1 && row-arr[i][0]==col-arr[i][1] && arr[i][0]<row)if(arr[i][0]>paschap[0]){paschap=arr[i];paschap[0]+=1; paschap[1]+=1;}
}

    
     int total=0;
                total+=col-chap[1];
     //cout<<total<<endl;
                total+=chaptep[0]-row;
     //cout<<total<<endl;
                total+=tep[0]-row;
     //cout<<total<<endl;
                total+=tepong[1]-col;
     //cout<<total<<endl;
                total+=ong[1]-col;
     //cout<<total<<endl;
                total+=ongpas[1]-col;
     //cout<<total<<endl;
                total+=row-pas[0];
     //cout<<total<<endl;
                total+=col-paschap[1];
     //cout<<total<<endl;
     
     return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
 
