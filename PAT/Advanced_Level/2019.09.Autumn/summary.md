A with 1 WA, reason: ingnore one condition to cut dfs branch.

B with 1 WA, resson: case: "n > 2m", cause some error, chage `for (int i = 0; i < n; ++i)` to `for (int i = 0; rear != -1; ++i)` get AC.

C with no WA

D with 1 WA, reson: index start from "1" and end with "n" but some array initialized with size `n` some `n + 1`, change to `n + 1`: AC.