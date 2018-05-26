# map

## map 컨테이너

대다수 응용프로그램에서 순차열 커넽이너가 편리한 데이터 액세스 도구 아님.

맵 컨테이너는 연관 컨테이너라 함.

객체를 객체와 연관된 키 값으로 위치 정함.



4가지 존재. 모두 키/값 쌍 저장

T객체와 객체와 연관된 키 K를 캡슐화한 pair<const K, T> 타입 객체를 map에 원소로 저장

- map<K,T> 키는 중복되면 안됨. 원소들은 정렬 되있음. 키를 비교해서 결정.

- multimap<K,T>는 map<K,T>와 유사. 그러나 중복키 허용

- unordered_map<K,T>는 키 값으로 정렬되어있지 않음. 키 값으로 생성된 해시 값 사용해 위치 정해짐.

- unordered_multymap<K,T>

위 2개는 map 헤더

나머지는 unordered_map 헤더파일

## map 사용

map 의 원소들은 less<K>로 정렬 한다고 오해 하면 안됨.

원소들을 균형 이진 트리로 저장.

트리의 높이 최소로 유지됨.

새 원소 추가 시 균형 트리구조 유지하려면, 오버헤드가 따름. 그 만큼 검색 효율이 올라감.



### 생성

매개 변수 4개, 보통 처음 두개에만 값 지정하면 됨.

1. 키 타입 2. 지정할 객체 타입

3,4 키를 비교하는ㄷ ㅔ사용할 함수 객체 타입. 맵 안에 메모리 할당하는 데 사용할 객체의 타입 정의



std::map<std::string, size_t> people;

원소들은 pair<std::string, size_t> 타입

초깃값은 반드시 pair<const K, T> 타입

std::map<std::string, size_t> map people {{"A",25}, {"B",30}}; // make_pair("A",25)

pair 객체는 public 멤버 first, second에 있음



### 원소 삽입

auto pr = std::make_pair("Fi",22);

auto retpr = people.insert(pr);

//retpr.first->first : Fi, retpr->second : true



insert()함수멤버는 pair<iterator, bool> 객체 반환

삽입된 원소 똔느 방해한 원소를 가리키는 반복자 . 못한 경우는 키가 중복

두 번째는 성공 여부

count()멤번느 맵에 해당 키를 갖고 있는 원소 개수 반환(0or 1)

### map원소 내부에서 생성

emplace()반환값은 insert()와 동일

empalce_hint()로 첫 인수로 지정한 반복잘르 새 원소 생성을 위한 탐색 시작 위치로 사용. 반환은 삽입된 새 원소 가리키는 반복자나 삽입 실패시, 키가 같은 원소 가리키는 반복자 반환

### map 원소에 접근

auto age = people[Name{"Dan","DF"}];

키가 없다면 키로 새 원소 생성
