## Wordfinder

Text file 내에서 원하는 단어를 찾을 수 있는 word finder 개발



####  Input

- Sample file : text file
- Regular expression
  ▪ {n} : char가 n번 (1 ≤ 𝑛 ≤ 9)
  ➢ ex) {3}ing = coming, saying, eating
  ▪ 검색어: {n}String{n’}, {n}String, String{n’}
  ➢ ex) {4}com{5}, {3}ing, com{3}
  ▪ 과제 내에서 정의한 정규식은 POSIX Regular expression과는 다름
  • Function & Output
- 사용자가 입력한 표현을 Sample text file에서 찾아 순서대로 화면에 출력
  ▪ line#num : word
  ▪ line#num : word, word’
- 단어 찾기를 5회 반복 수행 후 종료



#### 주의 사항

- Cygwin 환경에서 컴파일하여 실행 파일을 만들 것
  ▪ 다른 환경에서 컴파일하여 만든 실행파일을 제출하여 실행이 안될 경우 ‘0점’ 처리
- 코드파일과 실행파일 이름은 “wordfinder”로 명명할 것.
  ▪ 코드파일: wordfinder.c
  ▪ 실행파일: wordfinder.exe
- Sample text file은 프로그램이 실행되는 디렉토리와 같은 위치에 존재하며, 프
  로그램 실행 시 별도의 조작없이 자동으로 읽어 수행할 수 있도록 할 것
  ▪ Sample text file 이름은 “sample.txt”로 명명
  ➢ 과제는 sample.txt 파일로 평가할 예정.
- 실행 시 첫 화면에 “학번_이름”이 출력되도록 할 것



####  검색 기능 상세 사항

- 3가지 검색 기능 구현: {n}word{n’}, {n}word, word{n}

- 검색 시 발견한 단어의 line 수와 발견한 단어를 출력

- 같은 line에 2개 이상의 단어가 존재할 시 “, ”(comma) 로 구분


- 검색 기능 상세 사항: {n}word
  - n 만큼 word 앞에 문자 존재.
  - 즉, 검색 결과의 글자수는 n + word 글자수



-  검색 기능 상세 사항: word {n}
  - n 만큼 word 뒤에 문자 존재.
  - 즉, 검색 결과의 글자수는 word 글자수 + n



- 검색 기능 상세 사항: {n}word{n’}
  - n 만큼 word 앞에 문자 존재하고 n’ 만큼 word 뒤에 존재.
  - 즉, 검색 결과의 글자수는 n + word 글자수 + n’

