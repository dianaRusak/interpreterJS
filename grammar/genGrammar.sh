set -o errexit
LOCATION=/home/botinok/CLionProjects/antlr-4.8-complete.jar
java -jar $LOCATION -Dlanguage=Cpp -listener -visitor -o ../src/gen/ JavaScriptLexer.g4 JavaScriptParser.g4