#include <iostream>
using namespace std;

const int a = 10005;
const int b = 100;
const int c = 10005;

int d(const char e[]) {
    int f = 0;
    while (e[f] != '\0') f++;
    return f;
}

char g(char h) {
    if (h >= 'A' && h <= 'Z') return h + ('a' - 'A');
    return h;
}

bool i(char j, char k, bool l) {
    if (l) {
        j = g(j);
        k = g(k);
    }
    return j == k;
}

int m(const char n[], const char o[], bool p, long long& q, int& r) {
    q = 0;
    r = 0;

    int s = d(n);
    int t = d(o);

    if (t == 0) return 0;
    if (t > s) return -1;

    for (int u = 0; u <= s - t; u++) {
        r++;
        int v = 0;

        while (v < t) {
            q++;

            if (!i(n[u + v], o[v], p))
                break;

            v++;
        }

        if (v == t) return u;
    }

    return -1;
}

int w(const char n[], const char o[], bool p, int x[], int y, long long& q, int& r) {
    q = 0;
    r = 0;

    int s = d(n);
    int t = d(o);

    if (t == 0) {
        if (y > 0) {
            x[0] = 0;
            return 1;
        }
        return 0;
    }

    if (t > s) return 0;

    int z = 0;

    for (int u = 0; u <= s - t; u++) {
        r++;
        int v = 0;

        while (v < t) {
            q++;

            if (!i(n[u + v], o[v], p))
                break;

            v++;
        }

        if (v == t && z < y)
            x[z++] = u;
    }

    return z;
}

int aa(const int ab[], int s, const int o[], int t, long long& q, int& r) {
    q = 0;
    r = 0;

    if (t == 0) return 0;
    if (t > s) return -1;

    for (int u = 0; u <= s - t; u++) {
        r++;
        int v = 0;

        while (v < t) {
            q++;

            if (ab[u + v] != o[v])
                break;

            v++;
        }

        if (v == t) return u;
    }

    return -1;
}

int ac(const int ab[], int s, const int o[], int t, int x[], int y, long long& q, int& r) {
    q = 0;
    r = 0;

    if (t == 0) {
        if (y > 0) {
            x[0] = 0;
            return 1;
        }
        return 0;
    }

    if (t > s) return 0;

    int z = 0;

    for (int u = 0; u <= s - t; u++) {
        r++;
        int v = 0;

        while (v < t) {
            q++;

            if (ab[u + v] != o[v])
                break;

            v++;
        }

        if (v == t && z < y)
            x[z++] = u;
    }

    return z;
}

bool ad(const int ae[], int af, const int ag[], int ah) {
    if (af != ah) return false;

    for (int ai = 0; ai < af; ai++) {
        if (ae[ai] != ag[ai])
            return false;
    }

    return true;
}

int main() {
    int aj = 0;
    int ak = 0;

    int al[c];

    long long q;
    int r;

    cout << "PRACTICAL WORK 8 - DIRECT SUBSTRING SEARCH\n\n";

    cout << "AUTOMATED TEXT TESTS\n";

    const char* am[14] = {
        "algorithm", "algorithm", "algorithm", "algorithm",
        "aaaa", "abababa", "abc", "Data data DATA",
        "one two two", "", "hello hello", "mississippi",
        "abcabc", "same"
    };

    const char* an[14] = {
        "algo", "rith", "thm", "sort",
        "aa", "aba", "abcd", "data",
        "two", "x", "", "issi",
        "abc", "same"
    };

    int ao[14] = {
        0, 4, 6, -1, 0, 0, -1, 5,
        4, -1, 0, 1, 0, 0
    };

    int ap[14] = {
        1, 1, 1, 0, 3, 3, 0, 1,
        2, 0, 1, 2, 2, 1
    };

    int aq[14][5] = {
        { 0 },{ 4 },{ 6 },{ -1 },{ 0, 1, 2 },
        { 0, 2, 4 },{ -1 },{ 5 },{ 4, 8 },
        { -1 },{ 0, 6 },{ 1, 4 },{ 0, 3 },{ 0 }
    };

    for (int ar = 0; ar < 14; ar++) {
        int as = m(
            am[ar], an[ar], false, q, r
        );

        if (as == ao[ar])
            aj++;

        int at = w(
            am[ar], an[ar], false, al,
            c, q, r
        );

        if (ad(
            al, at, aq[ar], ap[ar]
        )) {
            ak++;
        }

        cout << "Text test " << ar + 1 << ": "
            << ((as == ao[ar] &&
                ad(al, at,
                    aq[ar], ap[ar]))
                ? "PASS" : "FAIL") << "\n";
    }

    cout << "\nAUTOMATED NUMERIC TESTS\n";

    int au[] = { 1, 2, 1, 2, 1 };
    int av[] = { 1, 2, 1 };

    int aw[] = { 4, 5, 6 };
    int ax[] = { 5, 7 };

    int ay[] = { 7, 8, 9 };
    int az[] = { 8 };

    int* ba[3] = { au, aw, ay };
    int* bb[3] = { av, ax, az };

    int bc[3] = { 5, 3, 3 };
    int bd[3] = { 3, 2, 1 };

    int be[3] = { 0, -1, 1 };
    int bf[3] = { 2, 0, 1 };

    int bg[3][3] = {
        { 0, 2 },{ -1 },{ 1 }
    };

    int bh = 0;
    int bi = 0;

    for (int ar = 0; ar < 3; ar++) {
        int as = aa(
            ba[ar], bc[ar], bb[ar], bd[ar],
            q, r
        );

        if (as == be[ar])
            bh++;

        int at = ac(
            ba[ar], bc[ar], bb[ar], bd[ar],
            al, c, q, r
        );

        if (ad(
            al, at,
            bg[ar], bf[ar]
        )) {
            bi++;
        }

        cout << "Numeric test " << ar + 15 << ": "
            << ((as == be[ar] &&
                ad(al, at,
                    bg[ar], bf[ar]))
                ? "PASS" : "FAIL") << "\n";
    }

    cout << "\nEMPTY PATTERN CHECK\n";

    const char bj[] = "abc";
    const char bk[] = "";

    int bl = m(
        bj, bk, false, q, r
    );

    int bm = w(
        bj, bk, false,
        al, c, q, r
    );

    bool bn = bl == 0 &&
        bm == 1 &&
        al[0] == 0;

    if (bn) {
        aj++;
        ak++;
    }

    cout << "Empty pattern: "
        << (bn ? "PASS" : "FAIL") << "\n";

    int bo[1] = { 0 };

    int bp = aa(
        au, 5, bo, 0, q, r
    );

    int bq = ac(
        au, 5, bo, 0,
        al, c, q, r
    );

    bool br = bp == 0 &&
        bq == 1 &&
        al[0] == 0;

    cout << "Empty numeric pattern: "
        << (br ? "PASS" : "FAIL") << "\n";

    cout << "Successful first-occurrence tests: "
        << aj << "/15\n";

    cout << "Successful all-occurrences tests: "
        << ak << "/15\n";

    cout << "Successful numeric first-occurrence tests: "
        << bh << "/3\n";

    cout << "Successful numeric all-occurrences tests: "
        << bi << "/3\n";

    cout << "Empty numeric pattern rule: "
        << (br ? "PASS" : "FAIL") << "\n";

    cout << "\nVARIANT 5\n";

    const char bs[] = "repeat repeatable repeated repeat";
    const char bt[] = "repeat";

    int as = m(
        bs, bt, false, q, r
    );

    cout << "Text: " << bs << "\n";
    cout << "Pattern: " << bt << "\n";
    cout << "First occurrence: " << as << "\n";
    cout << "First search comparisons: " << q << "\n";
    cout << "First search checked positions: " << r << "\n";

    int at = w(
        bs, bt, false,
        al, c, q, r
    );

    cout << "All occurrences: ";

    for (int ar = 0; ar < at; ar++) {
        cout << al[ar]
            << (ar + 1 < at ? ", " : "\n");
    }

    cout << "All search comparisons: " << q << "\n";
    cout << "All search checked positions: " << r << "\n";

    cout << "\nCASE SENSITIVITY CHECK\n";

    const char bu[] = "Case sensitive CASE case";
    const char bv[] = "case";

    int bw = m(
        bu, bv, false, q, r
    );

    cout << "Case-sensitive first index: "
        << bw << "\n";

    int bx = m(
        bu, bv, true, q, r
    );

    cout << "Case-insensitive first index: "
        << bx << "\n";

    cout << "\nOVERLAPPING MATCHES CHECK\n";

    const char by[] = "aaaa";
    const char bz[] = "aa";

    at = w(
        by, bz, false,
        al, c, q, r
    );

    cout << "Text: aaaa; pattern: aa; positions: ";

    for (int ar = 0; ar < at; ar++) {
        cout << al[ar]
            << (ar + 1 < at ? ", " : "\n");
    }

    cout << "\nEXPERIMENT RESULTS\n";

    cout << "n; scenario; first index; all matches; comparisons; checked positions\n";

    const char ca[] = "abcde";
    const int cb[3] = { 100, 1000, 10000 };

    char cc[a];

    for (int cd = 0; cd < 3; cd++) {
        int n = cb[cd];

        for (int ce = 0; ce < 4; ce++) {
            for (int ar = 0; ar < n; ar++)
                cc[ar] = 'x';

            cc[n] = '\0';

            if (ce == 0) {
                for (int cf = 0; cf < 5; cf++)
                    cc[cf] = ca[cf];
            }
            else if (ce == 1) {
                int cg = n / 2;

                for (int cf = 0; cf < 5; cf++)
                    cc[cg + cf] = ca[cf];
            }
            else if (ce == 2) {
                int cg = n - 5;

                for (int cf = 0; cf < 5; cf++)
                    cc[cg + cf] = ca[cf];
            }
            else {
                for (int ar = 0; ar + 5 < n; ar += 6) {
                    cc[ar] = 'a';
                    cc[ar + 1] = 'b';
                    cc[ar + 2] = 'c';
                    cc[ar + 3] = 'd';
                    cc[ar + 4] = 'z';
                    cc[ar + 5] = 'x';
                }
            }

            int ch = m(
                cc, ca, false, q, r
            );

            long long ci = q;
            int cj = r;

            int at = w(
                cc, ca, false, al,
                c, q, r
            );

            const char* ck[4] = {
                "A-start", "B-middle", "C-end", "D-absent-partial"
            };

            cout << n << "; " << ck[ce] << "; "
                << ch << "; " << at << "; "
                << ci << "; "
                << cj << "\n";
        }
    }

    return 0;
}
