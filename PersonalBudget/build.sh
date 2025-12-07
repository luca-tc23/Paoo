#!/usr/bin/env bash
set -e

echo "=== Building PersonalBudget ==="
cmake -S . -B build
cmake --build build

echo ""
echo "=== Build complete! ==="
echo "Run with: ./build/personal_budget"