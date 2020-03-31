копипаста:
1) example, по которому писался main https://github.com/teverett/antlr4-cpp-example/blob/master/hello.cpp
2) откуда грамматика - https://github.com/antlr/grammars-v4/tree/master/javascript/javascript

инструкция:
0) надеяться на чудо, что это соберется
1) магия по сборке antlr - https://github.com/antlr/antlr4/tree/master/runtime/Cpp
2) прекрасная магия плюсов с antlr, не генирирует он эти файлы, нужно качать ручками отсюда 
(но, т.к. я их в проекте тоже меняла, я добавила их в репозиторий)
https://github.com/antlr/grammars-v4/tree/master/javascript/javascript/Cpp  
Файлы JavaScriptParserBase.cpp, JavaScriptLexerBase.h, JavaScriptLexerBase.cpp, JavaScriptParserBase.h)
3) генерируем файлы по грамматике. 
3.1) Тыкаем на JavaScriptLexer.g4 в папке grammar, на Configure Antrl, пишем там вот так
![logo](https://i.ibb.co/7KLNcWW/2020-03-31-20-46-40.png)
3.2) То же самое с JavaScriptParser.g4
3.3) Ещё раз тыкаем на эти два файла и выбираем Generate ANTLR ...
4) вот этот путь в gen.sh - LOCATION=/home/botinok/CLionProjects/antlr-4.8-complete.jar - заменить на свой
5) с надеждой на зачет запустить gen.sh

