/*
 * Complexidade : O(N)
 */

ll solve(vi &h)
{
  int n = h.size();
  ll resp = 0;
  stack<int> pilha;
  ll i = 0;
  while (i < n) {
    if (pilha.empty() or h[pilha.top()] <= h[i]) {
      pilha.push(i++);
    }
    else {
      int aux = pilha.top();
      pilha.pop();
      resp =
          max(resp, (ll)h[aux] * ((pilha.empty()) ? i + 1 : i - pilha.top()));
    }
  }
  while (!pilha.empty()) {
    int aux = pilha.top();
    pilha.pop();
    resp =
        max(resp, (ll)h[aux] * ((pilha.empty()) ? n + 1 : n - pilha.top()));
  }
  return resp;
}
