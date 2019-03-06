class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> S;
        for (auto email : emails)
        {
            string local, domain;
            int k = 0;
            while (email[k] != '@') k ++ ;
            local = email.substr(0, k);
            domain = email.substr(k + 1);
            string newLocal;
            for (auto c : local)
            {
                if (c == '+') break;
                if (c != '.') newLocal += c;
            }
            S.insert(newLocal + '@' + domain);
        }
        return S.size();
    }
};
