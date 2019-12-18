#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <array>
#include <numeric>

using namespace std;

#define CLASS_TYPE_NUM 10

int SoftmaxWithArgMax(std::vector<float> &input) {
    auto max_iter = std::max_element(input.begin(), input.end());
    int max_arg = std::distance(std::begin(input), max_iter);
    float m = *max_iter;
    double sum = 0.0;
    for (size_t i = 0; i < CLASS_TYPE_NUM; i++) {
        input[i] -= m;
        sum += exp(input[i]);
    }
    for (size_t i = 0; i < CLASS_TYPE_NUM; i++) {
        input[i] = (float)(exp(input[i])/sum);
        // std::cout << input[i] <<" ";
    }
    // std::cout << std::endl;
    return max_arg;
}

static int nn_forward(
    const std::vector<int>& X, 
    const std::vector<float>& W1, 
    const std::vector<float>& W2, 
    int N, int M, float* score) {
    // Begin forward
    std::vector<float> X1(M, 0.0f);
    for(int i = 0; i < M; i++) {
        // int start = i*N;
        // float a = 0.0f;
        // for(int j = 0; j < N; j++) {
        //     a += X[j]*W1[start + j];
        // }
        float a = std::inner_product(X.begin(), X.end(), W1.begin() + i*N, 0.0f);
        X1[i] = std::max(0.0f, a);
    }
    std::vector<float> Y(CLASS_TYPE_NUM, 0.0f);
    for(int i = 0; i < CLASS_TYPE_NUM; i++) {
        // int start = i*M;
        // float a = 0.0f;
        // for(int j = 0; j < M; j++) {
        //     a += X1[j]*W2[start + j];
        // }
        // Y[i] = a;
        Y[i] = std::inner_product(X1.begin(), X1.end(), W2.begin() + i*M, 0.0f);
    }
    int class_type = SoftmaxWithArgMax(Y);
    *score = Y[class_type];
    return class_type;
}

int main() {
    std::ifstream cin("glint_3.txt");
    int N, M;
    cin >> N >> M;
    std::vector<int> X(N, 0);
    for(int i = 0; i < N; i++) cin >> X[i];
    const int total = M*N;
    std::vector<float> W1(total);
    for(int i = 0; i < total; i++) cin >> W1[i];
    std::vector<float> W2(10 * M);
    for(int i = 0; i < 10*M; i++) cin >> W2[i];

    float expect_score = 0.0f;
    int expect_class = nn_forward(X, W1, W2, N, M, &expect_score);

    int same_class_min_value = -129;
    int hack_index = -1;
    int hack_value = -129;
    int hack_same_index = -1;
    int hack_same_value = -129;
    float hack_max_score = -1.0f;
    float hack_min_score = expect_score;
    for(int ix = 0; ix < N; ix++) {
        const int source_value = X[ix];
        for(int i = -128; i < 128; i++) {
            if(i == source_value) continue;
            X[ix] = i;
            float score = 0;
            int new_class = nn_forward(X, W1, W2, N, M, &score);
            if(new_class != expect_class) {
                hack_index = ix;
                hack_max_score = score;
                hack_value = i;
                for(int j = i+1; j < 128; j++) {
                    new_class = nn_forward(X, W1, W2, N, M, &score);
                    if(new_class != expect_class){
                        if(score > hack_max_score) {
                            hack_max_score = score;
                            hack_value = j;
                        }
                    }
                }
                std::cout << hack_index + 1 << " " <<hack_value << std::endl;
                return 0;
            }else {
               if(hack_min_score > score) {
                    hack_same_index = ix;
                    hack_min_score = score;
                    hack_same_value = i;
                }
            }
        }
        X[ix] = source_value;
    }
    // if(hack_value == -129) {
    //     for(int ix = 0; ix < N; ix++) {
    //         const int source_value = X[ix];
    //         for(int i = -128; i < 128; i++) {
    //             if(i == source_value) continue;
    //             X[ix] = i;
    //             float score = 0;
    //             int new_class = nn_forward(X, W1, W2, N, M, &score);
    //             if(new_class == expect_class) {
    //                 if(hack_min_score > score) {
    //                     hack_index = ix;
    //                     hack_min_score = score;
    //                     hack_value = i;
    //                 }
    //             } 
    //         }
    //         X[ix] = source_value;
    //     }
    // }
//    if(hack_value == -129) {
        std::cout << hack_same_index + 1 << " " <<hack_same_value << std::endl;
    // } else {
    //     std::cout << hack_index + 1 << " " <<hack_value << std::endl;
    // }
    return 0;
}
