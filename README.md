# 🎮 텍스트 기반 로그라이크 게임 (C언어)

C언어로 만든 간단한 텍스트 기반 로그라이크 게임입니다.  
전투, 장비, 아이템 시스템을 직접 구조체로 구현했습니다.

## 📁 프로젝트 구조

├── Struct.h # 공용 구조체 정의 (Item, Player, Monster 등)
├── Player.h / .cpp # 플레이어의 행동, 경험치, 레벨업, 장비 착용 등
├── Monster.h / .cpp # 몬스터 생성, 전투, 드롭 테이블 관리
├── Merchant.h / .cpp # 상점 아이템 목록, 판매/구매 기능
├── Inventory.h / .cpp # 인벤토리 및 아이템 정리, 출력 기능
├── main.cpp # 메인 루프 및 게임 흐름 제어

---

## 🎮 주요 기능

| 기능 | 설명 |
|------|------|
| 🎒 인벤토리 시스템 | 아이템 추가, 사용, 장착, 정렬 (`CompactItemList`) 기능 포함 |
| 🧤 장비 시스템 | 무기, 머리, 몸통, 장갑, 다리 부위별 장착 지원 |
| 🛒 상점 | 포션 및 장비를 구매하고 소지금 차감 |
| 🐉 몬스터 | 경험치/골드/아이템 드롭 테이블 기반의 전투 시스템 |
| 스킬 시스템 | 텍스트 기반 게임의 지루함을 타파하기 위해 단순히 스킬을 선택해서 발동하는 것이 아닌 커맨드 입력 or 시간 내에 특정 행동을 성공(Ex. 주어진 시간 내에 스킬 명을 정확히 입력)할 시 스킬 발동 |
| 📈 성장 시스템 | 경험치 획득 → 레벨업 → 능력치 증가 |
| 💬 콘솔 인터페이스 | 입력 기반의 텍스트 UI로 플레이 진행 |

---

## 🛠 구현 과정

### 1. 구조체 설계 (`Struct.h`)
- `Item`, `Player`, `Monster`, `StoreTable` 등의 구조체 정의
- 인벤토리와 장비 슬롯 고정 크기 할당

### 2. 인벤토리 시스템 (`Inventory.cpp`)
- `PutInven`: 아이템 획득 시 인벤토리에 넣기  
- `CompactItemList`: 빈 슬롯 제거 및 정렬  
- `IsValidItem`: 아이템 유효성 판단  
- `PrintInven`: 현재 보유 아이템 출력
- `PrintEquip` : 현재 장착된 장비 출력
- `MakeEmptyItem` : Item을 초기화
- `PickAndDropItem` : 인벤토리가 꽉 찼을 시 습득 아이템을 얻을 지 버릴 지 선택 후, 습득 선택 시 기존 인벤토리의 아이템을 골라 습득 아이템으로 변경 // 구현 중

### 3. 전투 및 드롭 시스템 (`Monster.cpp`)
- `PrintStatus` : 몬스터의 스탯창 출력
- `CreateMonster` : 몬스터 이름을 인자로 받아 해당 이름의 몬스터 생성
- `PickRandomName` : 몬스터 이름 배열에서 랜덤한 하나의 값 추출
- `RollDrop` : 몬스터 드랍 테이블의 확률에 따라 랜덤한 아이템을 드랍

### 4. 상점 구현 (`Merchant.cpp`)
- `StoreTable` 기반 상점 아이템 목록
- `InitStoreTable` : StoreTable에 상점 아이템 목록을 하드코딩
- `InitMerchant`: StoreTable에 있는 아이템 목록을 랜덤하게 몇 개를 뽑아 상인의 아이템 테이블에 저장
- `SelectProduct` : 상인 아이템 목록에서 아이템을 골라 구매

### 5. 플레이어 (`Player.cpp`)
- `SelectAnimal` : 플레이할 동물 선택
- `PrintStatus` : 플레이어 스탯창 출력
- `UpdateExpAndLevel` : 경험치 획득 시 경험치 업데이트 및 레벨업 관리
- `InitInven` : 인벤토리 초기화
- `SelectAction` : 어떤 행동을 할 지 선택
- `Battle` : 몬스터와의 전투 관리
- `EquipItem` : 장비 장착
- `UnequipItem` : 장비 해제
- `SellItem` : 아이템 판매
- `SkillNameInput` : 스킬명을 정해진 시간 내에 정확히 입력해야 발동 // 구현 중, 입력 버퍼에 남은 값이 자꾸 다음 입력에 영향을 주고 있음
- `SkillRandomInput` : 주어진 랜덤한 버튼을 시간 내에 입력하면 발동 // 구현 중
- `SkillArrowCommandInput` : 주어진 시간 내에 커맨드 입력하면 발동 // 구현 중
- `PrintSkill` : 스킬 목록 출력
- `UseSkill` : 선택한 스킬 사용

### 6. 저장/불러오기 (`FileSave.cpp`)
- `CreateData` : 플레이어 데이터 저장
- `LoadData` : 저장된 플레이어 데이터 로드
---

## 💻 실행 환경

- Language: **C**
- IDE: Visual Studio 2022
- OS: Windows 10 이상
- 콘솔 기반 실행

---

## 📸 게임 스크린샷 (선택)

> 완성 후 게시

---

## 📌 배우고 느낀 점

- **구조화된 설계의 중요성**: 기능별 `.h / .cpp` 분리로 유지보수 용이
- **랜덤성과 상태 관리**: 드롭 테이블, 경험치, 레벨업 처리의 흐름 관리
- **텍스트 기반 UI**: 콘솔 입력/출력만으로도 유저와 상호작용 가능

---

## 📦 향후 개선 방향

- 몬스터 종류 및 맵 다양화
- 상태이상, 스킬, 퀘스트 시스템 추가

---

## 📂 실행 방법

```bash
# main.cpp 기준 실행
g++ -o rpg main.cpp Player.cpp Monster.cpp Merchant.cpp Inventory.cpp
./rpg
또는 Visual Studio에서 솔루션 실행
