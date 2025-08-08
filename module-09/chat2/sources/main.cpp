#include <iostream>
#include <vector>
#include <algorithm>

int depth = 0;         // recursion depth for debug
long long comparisons = 0; // global comparison count

bool cmp(int a, int b) {
    comparisons++;
    return a > b;
}

// Generate Jacobsthal sequence up to n
std::vector<int> jacobsthal(int n) {
    std::vector<int> seq;
    int j0 = 0, j1 = 1;
    seq.push_back(0);
    while (true) {
        int j2 = j1 + 2 * j0;
        if (j2 > n) break;
        seq.push_back(j2);
        j0 = j1;
        j1 = j2;
    }
    // Fill in missing numbers between the Jacobsthal ones
    for (int i = seq.back() - 1; i > 0; --i) {
        if (std::find(seq.begin(), seq.end(), i) == seq.end())
            seq.push_back(i);
    }
    return seq;
}

// Binary insert into sorted vector
void insert_sorted(std::vector<int>& sorted, int value) {
    auto it = std::lower_bound(sorted.begin(), sorted.end(), value, 
                               [](int x, int y){ comparisons++; return x < y; });
    sorted.insert(it, value);
}

std::vector<int> fordJohnson(const std::vector<int>& input) {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "Level " << depth 
              << " input: ";
    for (int v : input) std::cout << v << " ";
    std::cout << "\n";

    if (input.size() <= 1) return input;

    std::vector<int> mainChain;
    std::vector<int> pend;

    // Step 1: Pair and split into main & pend
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i], b = input[i + 1];
        if (cmp(a, b)) {
            mainChain.push_back(a);
            pend.push_back(b);
        } else {
            mainChain.push_back(b);
            pend.push_back(a);
        }
    }
    if (input.size() % 2 == 1) {
        pend.push_back(input.back());
    }

    std::cout << indent << "  Main: ";
    for (int v : mainChain) std::cout << v << " ";
    std::cout << "\n";

    std::cout << indent << "  Pend: ";
    for (int v : pend) std::cout << v << " ";
    std::cout << "\n";

    // Step 2: Recursively sort main chain
    depth++;
    mainChain = fordJohnson(mainChain);
    depth--;

    std::cout << indent << "  Sorted main: ";
    for (int v : mainChain) std::cout << v << " ";
    std::cout << "\n";

    // Step 3: Insert pend into main in Jacobsthal order
    auto order = jacobsthal(pend.size());
    std::cout << indent << "  Jacobsthal order: ";
    for (int o : order) std::cout << o << " ";
    std::cout << "\n";

    for (int idx : order) {
        if (idx == 0) continue; // skip zero
        if (idx <= (int)pend.size()) {
            std::cout << indent << "    Insert " << pend[idx - 1] << "\n";
            insert_sorted(mainChain, pend[idx - 1]);
        }
    }

    std::cout << indent << "  Result at level " << depth << ": ";
    for (int v : mainChain) std::cout << v << " ";
    std::cout << "\n";

    return mainChain;
}

long long insertionSortComparisons(std::vector<int> arr) {
    long long count = 0;
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && (++count && arr[j-1] > key)) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
    return count;
}

int main() {
    std::vector<int> data = {4, 2, 9, 1, 5, 3, 8, 6, 7};

    comparisons = 0;
    auto sorted = fordJohnson(data);
    std::cout << "\nFinal sorted: ";
    for (int x : sorted) {
        std::cout << x << " ";
    }
    std::cout << "\nFord–Johnson comparisons: " << comparisons << "\n";

    auto insCount = insertionSortComparisons(data);
    std::cout << "Insertion sort comparisons: " << insCount << "\n";
}
