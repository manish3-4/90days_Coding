if (year == 1918)
{
    return "26.09.1918"; // Transition year with a shift in the calendar
}
else if ((year < 1918 && year % 4 == 0) || // Julian leap year
         (year > 1918 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))))
{ // Gregorian leap year
    return "12.09." + to_string(year);
}
else
{
    return "13.09." + to_string(year);
}
[22:16, 2 / 15 / 2025] Anju : int R = G.size(), C = G[0].size();
int r = P.size(), c = P[0].size();

for (int i = 0; i <= R - r; i++)
{
    for (int j = 0; j <= C - c; j++)
    {
        bool found = true;
        for (int k = 0; k < r; k++)
        {
            if (G[i + k].substr(j, c) != P[k])
            {
                found = false;
                break;
            }
        }
        if (found)
            return "YES";
    }
}
return "NO";
[22:18, 2 / 15 / 2025] Anju : vector<int> unique_ranks;
unique_ranks.push_back(ranked[0]);
for (int i = 1; i < ranked.size(); i++)
{
    if (ranked[i] != ranked[i - 1])
    {
        unique_ranks.push_back(ranked[i]);
    }
}

vector<int> results;
int index = unique_ranks.size() - 1;
for (int score : player)
{
    while (index >= 0 && score >= unique_ranks[index])
    {
        index--;
    }
    results.push_back(index + 2);
}
return results;
[22:22, 2 / 15 / 2025] Anju : set<pair<int, int>> obstacleSet;
for (const auto &obs : obstacles)
{
    obstacleSet.insert({obs[0], obs[1]});
}

vector<pair<int, int>> directions = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int attackableSquares = 0;

for (const auto &[dx, dy] : directions)
{
    int r = r_q + dx, c = c_q + dy;
    while (r > 0 && r <= n && c > 0 && c <= n && obstacleSet.find({r, c}) == obstacleSet.end())
    {
        attackableSquares++;
        r += dx;
        c += dy;
    }
}

return attackableSquares;