# cppdcov-poc

[![codecov](https://codecov.io/gh/HuaTsai/cppcov-poc/graph/badge.svg?token=3U3E8GDYPM)](https://codecov.io/gh/HuaTsai/cppcov-poc)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=HuaTsai_cppcov-poc&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=HuaTsai_cppcov-poc)

## Graphs

- Sunburst

  ![Sunburst](https://codecov.io/gh/HuaTsai/cppcov-poc/graphs/sunburst.svg?token=3U3E8GDYPM)

- Grid

  ![Grid](https://codecov.io/gh/HuaTsai/cppcov-poc/graphs/tree.svg?token=3U3E8GDYPM)

- Icicle

  ![Icicle](https://codecov.io/gh/HuaTsai/cppcov-poc/graphs/icicle.svg?token=3U3E8GDYPM)

## Coverage Tools

Choose one of the following tools to generate the coverage report.

1. lcov

  ```bash
  sudo apt install lcov
  lcov -c -d build -o coverage.info
  lcov -r coverage.info '/usr/*' '*test*' -o coverage.info
  genhtml coverage.info -o coverage
  ```

2. gcovr

  ```bash
  pip install gcovr
  mkdir coverage
  gcovr -r . --html --html-details coverage/index.html --exclude '.*test.*' --exclude-throw-branches
  ```

  For SonarQube CI: `gcovr -r . --sonarqube --exclude '.*test.*' --exclude-throw-branches > coverage.xml`

