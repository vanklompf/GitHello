uint32_t runAndMeasure(void(*work)(void), int times) {
    std::chrono::steady_clock::time_point start, end;
    start = std::chrono::steady_clock::now();

    for (auto i = 0; i < times; i++) {
        work();
    }

    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds).count();
}

