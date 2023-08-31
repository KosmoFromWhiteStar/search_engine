<h1 align="center"> Поисковой движок</h1>


## Описание
Поисковый движок представляет из себя консольное приложение (исполняемый файл, запускаемый на любом сервере или компьютере), осуществляющий поиск и имеющий возможность настройки через файлы формата JSON. Применённые в нём решения можно встроить в поисковый движок работающий на веб. 
Принципы работы поискового движка :
  1. В конфигурационном файле перед запуском приложения задаются названия файлов, по которым движок будет осуществлять поиск.
  2. Поисковый движок самостоятельно обходит все файлы и индексиретих так, чтобы потом по любому поисковому запросу находить наиболее релевантные документы.
  3. Пользователь задаёт запрос через JSON-файл requests.json. Запрос — это набор слов, по которым нужно найти документы.
  4. Запрос трансформирует в список слов.
  5. В индексе ищет те документы, на которых встречаются все эти слова.
  6. Результаты поиска ранжирует, сортирует и отдаёт пользователю, максимальное количество возможных документов в ответе задаётся в конфигурационном файле.
  7. В конце программа формирует файл answers.json, в который записывает результаты поиска.
