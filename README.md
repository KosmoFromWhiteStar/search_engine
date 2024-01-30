<h1 align="center"> Поисковой движок</h1>


## Описание
Поисковый движок представляет из себя консольное приложение (исполняемый файл, запускаемый на любом сервере или компьютере), осуществляющий поиск и имеющий возможность настройки через файлы формата JSON. Применённые в нём решения можно встроить в поисковый движок работающий на веб. 

## Принципы работы поискового движка :
  1. В конфигурационном файле перед запуском приложения задаются названия файлов, по которым движок будет осуществлять поиск.
  2. Поисковый движок самостоятельно обходит все файлы и индексиретих так, чтобы потом по любому поисковому запросу находить наиболее релевантные документы.
  3. Пользователь задаёт запрос через JSON-файл requests.json. Запрос — это набор слов, по которым нужно найти документы.
  4. Запрос трансформирует в список слов.
  5. В индексе ищет те документы, на которых встречаются все эти слова.
  6. Результаты поиска ранжирует, сортирует и отдаёт пользователю, максимальное количество возможных документов в ответе задаётся в конфигурационном файле.
  7. В конце программа формирует файл answers.json, в который записывает результаты поиска.

## Программные файлы
### config.json
Содержит общую информацию, без которой приложение не запускается.
```
{
  "config": {
      "name": "SkillboxSearchEngine",
      "version": "0.1",
      "max_responses": 5
      },
  "files":
  [  
    "../resources/file001.txt",
    "../resources/file002.txt",
    "../resources/file003.txt",
    "../resources/file004.txt",
    ...
  ]
}
```
### request.json

Содержит запросы, которые необходимо обработать поисковому движку
```
{
  "requests": [
    "some words..",
    "some words..",
    "some words..",
    "some words..",
    ...
    ]
}
```

### answere.json
В этот файл записываются результаты работы поискового движка. 
!!! Файл при каждом поиске обновляется и не содержит информации предыдущего поиска!!!
```
{
  "answers": {
    "request001": {
      "result": "true",
      "relevance": {
        "docid": 0, “rank” : 0.989,
        "docid": 1, “rank” : 0.897,
        "docid": 2, “rank” : 0.750,
        "docid": 3, “rank” : 0.670,
        "docid": 4, “rank” : 0.561
        }
    },
    "request002": {
      "result": "true",
      "docid": 0, “rank” : 0.769
      },
    "request003": {
        "result": "false"
        }
  }
}
```


## Технологии в проекте
  Для работы с JSON-файлами используется ["JSON for Modern C++"](https://github.com/nlohmann/json).
  
  Для проверки работы отдельных классов используется [Gtest](https://github.com/google/googletest)

## Нюансы
1. Индексирование файлов происходит в многопоточном режиме.
2. Сортировка происходит вставками, что не подходит для большого количества данных
3. Пути для ресурсов могут не соответствовать.

## Установка
!!! Важное помечание. Путь к файлам может отличатся, чтобы поправить при инициализации Converter_JSON  укажите путь к папке Conf.
Пример
```
Converter_JSON file(path);
```
Сборка:
  ```
  cmake -S <source_dir> -B <build_dir> -G "MinGW Makefiles"
  cmake --build <build_dir>
  ```

## Запуск
Программы:
```
<build_dir>\src\search_engine.exe
```
Тестов:
```
<build_dir>\tests\test.exe
```

## Тесты

Сами тесты в папке [test](https://github.com/KosmoFromWhiteStar/search_engine/tree/master/tests)

Вывод самих тестов:
```
[==========] Running 5 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 3 tests from TestCaseInvertedIndex
[ RUN      ] TestCaseInvertedIndex.TestBasic
[       OK ] TestCaseInvertedIndex.TestBasic (2 ms)
[ RUN      ] TestCaseInvertedIndex.TestBasic2
[       OK ] TestCaseInvertedIndex.TestBasic2 (2 ms)
[ RUN      ] TestCaseInvertedIndex.TestInvertedIndexMissingWord
[       OK ] TestCaseInvertedIndex.TestInvertedIndexMissingWord (1 ms)
[----------] 3 tests from TestCaseInvertedIndex (13 ms total)

[----------] 2 tests from TestCaseSearchServer
[ RUN      ] TestCaseSearchServer.TestSimple
[       OK ] TestCaseSearchServer.TestSimple (2 ms)
[ RUN      ] TestCaseSearchServer.TestTop5
[       OK ] TestCaseSearchServer.TestTop5 (6 ms)
[----------] 2 tests from TestCaseSearchServer (14 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 2 test suites ran. (35 ms total)
[  PASSED  ] 5 tests.
```
