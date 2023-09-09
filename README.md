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

## Технологии в проекте
  Для работы с JSON-файлами используется ["JSON for Modern C++"](https://github.com/nlohmann/json).
  
  Для проверки работы отдельных классов используется [Gtest](https://github.com/google/googletest)

## Нюансы
1. Индексирование файлов происходит в многопоточном режиме.
2. Сортировка происходит вставками, что не подходит для большого количества данных
3. Пути для рессурсов могут не соответствовать.
4. Тесты запускаются при запуске программы.

## Установка
Сборка:
  cmake -S <source_dir> -B <build_dir> -G "MinGW Makefiles"
  cmake --build <build_dir>

##Тесты

Сами тесты в папке [test](https://github.com/KosmoFromWhiteStar/search_engine/tree/master/tests)
![image](https://github.com/KosmoFromWhiteStar/search_engine/assets/104075230/b95413a6-23cd-4e11-be06-c25f9739c7fd)
