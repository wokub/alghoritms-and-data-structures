// Pseudokod z zajęć
bool* sito(bool prime[n]) {
    bool prime[n];

    for(int i = 0; i <= n; i++) {
        prime[i] = true;
    }

    for(int i = 2; i*i <= n; i++) {
        if(prime[i] == true) {
            for(int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    prime[0] = prime[1] = false;

    return prime;
}

int main () {
}
