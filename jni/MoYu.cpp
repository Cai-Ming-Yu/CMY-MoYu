
/*
    Copyright © 2023-2023 彩銘羽 (GitHubホーム: https://github.com/Cai-Ming-Yu)
    GitHub Repo: https://github.com/Cai-Ming-Yu/CMY-MoYu
*/

#define 彩銘羽 main

#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <random>
#include <thread>
#include <fstream>
#include <string>
#include "ChaCha20.h"

using namespace std;

const string RUN_UI = "CMD_UI";   // CMD_UI or NONE_UI
const int proc = 5;               // Number of concurrency
const int runTime = 30;           // Elapsed time
const int file = 2 * 1024 * 1024; // File size

void runner(const key256_t &key, const nonce96_t &nonce, int &counter)
{
    ChaCha20_Ctx ctx;
    ChaCha20_init(&ctx, key, nonce, 0);

    uint8_t *data = new uint8_t[file];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 255);
    for (int i = 0; i < file; ++i)
    {
        data[i] = dis(gen);
    }

    uint8_t *buffer = data;

    auto start = chrono::steady_clock::now();
    auto end = start + chrono::seconds(runTime);

    while (chrono::steady_clock::now() < end)
    {
        ChaCha20_xor(&ctx, buffer, file);
        ++counter;
    }

    delete[] data;
}

string sysInfo()
{
#ifdef _WIN32
    return "Windows";
#elif __linux__
    return "Linux";
#else
    return "Unknown";
#endif
}

int 彩銘羽()
{
    vector<thread> threads(proc);
    vector<int> counters(proc);

    if (RUN_UI == "CMD_UI")
    {

        printf("モーユーへようこそ！\n\n");

        cout << "このデバイスは、 " << sysInfo() << "プラットフォームで動作しているシステムである。" << endl
             << endl;

        printf("30秒間のCPUパフォーマンステストを行いますので、しばらくお待ちください\n\n");
    }

    for (int i = 0; i < proc; ++i)
    {
        key256_t key;
        nonce96_t nonce;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 255);
        for (int k = 0; k < sizeof(key); ++k)
        {
            key[k] = dis(gen);
        }
        for (int k = 0; k < sizeof(nonce); ++k)
        {
            nonce[k] = dis(gen);
        }

        threads[i] = thread(runner, std::ref(key), std::ref(nonce), std::ref(counters[i]));
    }

    if (RUN_UI == "CMD_UI")
    {

        auto start = chrono::steady_clock::now();
        auto end = start + chrono::seconds(runTime);

        int total;

        for (int i = 0; i <= runTime; ++i)
        {
            auto now = chrono::steady_clock::now();
            double elapsedTime = chrono::duration_cast<chrono::seconds>(now - start).count();
            int progress = static_cast<int>((elapsedTime / runTime) * 100);
            progress = min(progress, 100);

            if (i == runTime)
            {
                for (auto &thread : threads)
                {
                    thread.join();
                }
            }

            if (elapsedTime > runTime)
            {
                elapsedTime = runTime;
            }

            cout << "\r";
            cout << "\033[K";

            cout << "稼働中: [";
            int numEquals = (progress * 10) / 100;
            for (int j = 0; j < numEquals; ++j)
            {
                cout << "=";
            }
            cout << ">";
            for (int j = numEquals + 1; j < 10; ++j)
            {
                cout << "-";
            }
            cout << "] " << right << setw(3) << progress << "%";

            total = 0;
            for (const auto &counter : counters)
            {
                total += counter;
            }

            double remainingTime = max(0.0, (double)runTime - elapsedTime);
            cout << right << setw(6) << elapsedTime << "秒間/" << runTime << "秒間";
            cout << "  " << right << setw(8) << "スコア: " << total << "点";

            cout << flush;

            if (now < end)
            {
                this_thread::sleep_for(chrono::seconds(1));
            }
        }

        cout << endl
             << endl;
        cout << "セントラル・プロセッシング・ユニットの性能テスト終了！ あなたのCPUスコア：";
        total = 0;
        for (const auto &counter : counters)
        {
            total += counter;
        }
        cout << total << " 点！" << endl
             << endl;

        printf("ご利用ありがとうございます！ 著者：彩銘羽 (GitHubホーム: https://github.com/Cai-Ming-Yu)\n");
        printf("GitHub Repo: https://github.com/Cai-Ming-Yu/CMY-MoYu\n");
    }
    else if (RUN_UI == "NONE_UI")
    {

        for (auto &thread : threads)
        {
            thread.join();
        }
        int total = 0;
        for (const auto &counter : counters)
        {
            total += counter;
        }
        cout << total;
    }

    return 0;
}