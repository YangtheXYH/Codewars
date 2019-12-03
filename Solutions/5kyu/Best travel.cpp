/*
https://www.codewars.com/kata/best-travel
John and Mary want to travel between a few towns A, B, C ... Mary has on a sheet
of paper a list of distances between these towns. ls = [50, 55, 57, 58, 60].
John is tired of driving and he says to Mary that he doesn't want to drive more
than t = 174 miles and he will visit only 3 towns.
Which distances, hence which towns, they will choose so that the sum of the
distances is the biggest possible - to please Mary - but less than t - to please
John- ?
Example:
With list ls and 3 towns to visit they can make a choice between:
[50,55,57],[50,55,58],[50,55,60],[50,57,58],[50,57,60],[50,58,60],[55,57,58],[55,57,60],[55,58,60],[57,58,60].
The sums of distances are then: 162, 163, 165, 165, 167, 168, 170, 172, 173,
175.
The biggest possible sum taking a limit of 174 into account is then 173 and the
distances of the 3 corresponding towns is [55, 58, 60].
The function chooseBestSum (or choose_best_sum or ... depending on the language)
will take as parameters t (maximum sum of distances, integer >= 0), k (number of
towns to visit, k >= 1) and ls (list of distances, all distances are positive or
null integers and this list has at least one element). The function returns the
"best" sum ie the biggest possible sum of k distances less than or equal to the
given limit t, if that sum exists, or otherwise nil, null, None, Nothing,
depending on the language. With C++ return -1.
Examples:
ts = [50, 55, 56, 57, 58] choose_best_sum(163, 3, ts) -> 163
xs = [50] choose_best_sum(163, 3, xs) -> nil (or null or ... or -1 (C++)
ys = [91, 74, 73, 85, 73, 81, 87] choose_best_sum(230, 3, ys) -> 228
*/

//My solution
class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int>& ls);
};

int BestTravel::chooseBestSum(int t, int k, std::vector<int>& ls)
{
  if(ls.size() < k)
    return -1;
  
  std::sort(ls.begin(), ls.end(), std::greater<int>());
  int bestSum = -1;
  
  std::vector<int> bitmask(k, 1);
  bitmask.resize(ls.size(), 0);
  
  do {
      int test = 0;
      for (int i = 0; i < ls.size(); i++)
        if (bitmask[i]) 
          test += ls[i];
      if (test <= t && test > bestSum) 
          bestSum = test;
     } while (prev_permutation(bitmask.begin(), bitmask.end()));
  
  if(bestSum > t)
    return -1;
  else 
    return bestSum;
}

//Clever one
class BestTravel
{
public:
    static int chooseBestSum(int t, int k, const vector<int>& ls);
};

int BestTravel::chooseBestSum(int t, int k, const vector<int>& ls) {
    //cout << t << ' ' << k << endl;
    int n = ls.size();
    if (n < k) return -1;
    int ret{0};
    string bitmask(k, 1);
    bitmask.resize(n, 0);
    do {
      //for (int b:bitmask) cout << b << ' ';
      //cout << endl;
      int sum{0};
      for (int i = 0; i < n; ++i)
        if (bitmask[i]) sum += ls[i];
      if (sum <= t && sum > ret) ret = sum; 
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
    if (ret > 0) return ret;
    return -1;
}

//This one is what a kind of style I like
/*  
 *  Stop giving me classes with only
 *  one static method! Geez....
 */
namespace BestTravel
{

void getBestValue(std::vector<int> &dist, int max, int depth,
        int curValue, int lastIdx, int &sum)
{
    // start in the begining
    int i = 0;
    // generic name, waiting for the code review
    int value;

    // let's go!
    for (std::vector<int>::iterator it = dist.begin();
            it < dist.end(); it++, i++)
    {
        // there is no looking back now
        if (i <= lastIdx)
            continue;

        // best result achieved, get out of here!
        if (sum == max && sum != -1)
            break;

        // maybe I should store this
        value = curValue + (*it);

        // nah, too big
        if (value > max)
            continue;

        // should I go deeper?
        if (depth > 1)
            getBestValue(dist, max, depth - 1, value, i, sum);

        // I hope this is the one!
        if (depth == 1 && value > sum)
            sum = value;
    }
}

int chooseBestSum(int t, int k, std::vector<int>& ls)
{
    // final result
    int sum = -1;
    // start BIG!
    std::sort(ls.rbegin(), ls.rend());

    // did i say recursion?
    getBestValue(ls, t, k, 0, -1, sum);

    //gg
    return sum;
}

};
