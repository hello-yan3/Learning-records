# ✅ 第一部分：JSON 语法详解（JavaScript Object Notation）

JSON 是一种轻量级的数据交换格式，基于 JavaScript 的一个子集，但独立于语言，广泛用于 Web API、配置文件、数据存储等。

## 🔹 基本语法规则

| 类型                  | 语法                      | 说明                                                         |
| --------------------- | ------------------------- | ------------------------------------------------------------ |
| **对象（Object）**    | `{ }`                     | 键值对集合，键必须是字符串，值可以是任意合法类型。键和值之间用 `:` 分隔，多个键值对用 `,` 分隔。 |
| **数组（Array）**     | `[ ]`                     | 有序值列表，值可以是任意合法类型，用 `,` 分隔。              |
| **字符串（String）**  | `"..."`                   | 必须用双引号包裹，支持转义字符如 `\n`, `\t`, `\"`, `\\` 等。 |
| **数字（Number）**    | `123`, `-45.67`, `0.1e-3` | 整数或浮点数，不支持八进制/十六进制（如 `0x1A` 无效）。      |
| **布尔值（Boolean）** | `true`, `false`           | 小写，不能用 `"true"`（那是字符串）。                        |
| **空值（Null）**      | `null`                    | 表示“无值”，不是字符串 `"null"`。                            |

## 🔹 示例：完整的 JSON 文档

```json
{
  "name": "张三",
  "age": 28,
  "isStudent": false,
  "address": {
    "city": "北京",
    "street": "长安街"
  },
  "hobbies": ["读书", "游泳", "编程"],
  "phone": null,
  "scores": [95, 87, 92]
}
```

### ✅ 合法性检查要点：

| 项目                  | 是否允许 | 说明                                         |
| --------------------- | -------- | -------------------------------------------- |
| 单引号 `'key': value` | ❌ 不允许 | 必须双引号                                   |
| 尾随逗号 `{a:1,}`     | ❌ 不允许 | 标准 JSON 不支持（某些解析器宽容）           |
| 注释 `//` 或 `/* */`  | ❌ 不允许 | JSON 是纯数据格式，无注释                    |
| 键名未加引号          | ❌ 不允许 | `name: "张三"` → 错误！必须 `"name": "张三"` |
| 数字前导零 `0123`     | ❌ 不允许 | `123` 才合法                                 |
| 字符串中换行          | ❌ 不允许 | 可用 `\n` 转义                               |

> ⚠️ 注意：很多开发者误以为 JSON 支持注释或单引号 —— 这是错误认知！  
> 实际上这些是 **JavaScript 对象字面量**（JS Object Literal），不是标准 JSON。

---



# ✅ 第二部分：Qt 中 JSON 使用详解（QJson* 系列类）

Qt 提供了完整的 JSON 解析和生成工具，位于头文件：

```cpp
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
```

## 📦 核心类关系图（层级结构）

```
QJsonDocument
   │
   ├── QJsonObject  ← key-value 结构，类似 QMap<QString, QJsonValue>
   └── QJsonArray   ← 有序列表，类似 QList<QJsonValue>
         │
         └── QJsonValue ← 包装所有类型：String, Number, Bool, Null, Object, Array
```

> ✅ `QJsonValue` 是所有 JSON 值的基类，其他类型都是它的特化。

---

## 🔧 1. QJsonValue —— JSON 值的通用容器

表示任意一个 JSON 值（字符串、数字、布尔、null、对象、数组）。

### 构造方式：
```cpp
QJsonValue val1 = "Hello";              // 自动推断为 String
QJsonValue val2 = 3.14;                 // Double
QJsonValue val3 = true;                 // Bool
QJsonValue val4 = QJsonValue::Null;     // 显式 null
QJsonValue val5 = QJsonObject();        // Object
QJsonValue val6 = QJsonArray();         // Array
```

### 判断类型：
```cpp
if (val.isString())     qDebug() << val.toString();
if (val.isDouble())     qDebug() << val.toDouble();
if (val.isBool())       qDebug() << val.toBool();
if (val.isNull())       qDebug() << "It's null";
if (val.isObject())     qDebug() << "It's an object";
if (val.isArray())      qDebug() << "It's an array";
```

### 获取值：
```cpp
QString str = val.toString();           // 安全转换，如果是数字会自动转成字符串
double num = val.toDouble();            // 如果是字符串 "123" 也会转成 123.0
bool b = val.toBool();                  // "true" → true, "false" → false, 其他 → false
```

> 💡 注意：`toString()` 会把任何类型都转成字符串（比如数字 123 → "123"），非常方便！

---

## 🔧 2. QJsonObject —— 键值对对象（相当于 JS 对象）

### 创建和赋值：
```cpp
QJsonObject obj;
obj["name"] = "Alice";
obj["age"] = 30;
obj["isStudent"] = false;
obj["address"] = QJsonObject{{"city", "Shanghai"}, {"street", "Nanjing Road"}};

// 或者一次性初始化
QJsonObject obj2 = {
    {"name", "Bob"},
    {"score", 95.5},
    {"tags", QJsonArray{"good", "smart"}}
};
```

### 访问和遍历：
```cpp
// 检查是否存在
if (obj.contains("name")) {
    QString name = obj["name"].toString(); // "Alice"
}

// 遍历所有键值对
for (auto it = obj.begin(); it != obj.end(); ++it) {
    qDebug() << "Key:" << it.key() << ", Value:" << it.value().toString();
}

// 使用 keys()
QList<QString> keys = obj.keys();
for (const QString &key : keys) {
    qDebug() << key << ":" << obj[key];
}
```

### 删除键：
```cpp
obj.remove("age"); // 移除 age 键
```

---

## 🔧 3. QJsonArray —— 有序数组（相当于 JS 数组）

### 创建和添加元素：
```cpp
QJsonArray arr;
arr.append("Apple");
arr.append(100);
arr.append(true);
arr.append(QJsonValue::Null);

// 添加对象
QJsonObject person;
person["name"] = "Tom";
person["age"] = 25;
arr.append(person);

// 插入到指定位置
arr.insert(0, "First");
```

### 访问和遍历：
```cpp
qDebug() << arr.size(); // 5

// 按索引访问
QJsonValue v = arr[0]; // "First"
if (v.isString()) qDebug() << v.toString(); // 输出 "First"

// 遍历
for (int i = 0; i < arr.size(); ++i) {
    qDebug() << "Index" << i << ":" << arr[i];
}

// 或者用迭代器
for (const auto &val : arr) {
    if (val.isObject()) {
        QJsonObject obj = val.toObject();
        qDebug() << "Person:" << obj["name"];
    }
}
```

### 删除元素：
```cpp
arr.removeAt(0); // 删除第一个元素
```

---

## 🔧 4. QJsonDocument —— 封装整个 JSON 文档（根节点）

用于序列化（写）和反序列化（读）整个 JSON 数据。

### 从 QJsonObject/QJsonArray 构建文档：
```cpp
QJsonObject root;
root["title"] = "My Config";
root["version"] = 1.2;

QJsonDocument doc(root); // 包装为文档
```

### 序列化为字符串（JSON 格式）：
```cpp
QString jsonString = doc.toJson(QJsonDocument::Indented); // 带缩进美观格式
// 或
QString jsonString2 = doc.toJson(); // 压缩格式（无空格）

qDebug() << jsonString;
```

#### 输出结果：
```json
{
    "title": "My Config",
    "version": 1.2
}
```

### 从字符串解析为 QJsonDocument：
```cpp
QString jsonStr = R"({
    "name": "李四",
    "hobbies": ["读书", "跑步"],
    "metadata": {
        "created": "2024-01-01"
    }
})";

QJsonParseError parseError;
QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &parseError);

if (parseError.error != QJsonParseError::NoError) {
    qDebug() << "JSON 解析错误：" << parseError.errorString();
    return;
}

if (doc.isObject()) {
    QJsonObject obj = doc.object();
    QString name = obj["name"].toString(); // "李四"
    QJsonArray hobbies = obj["hobbies"].toArray();
    QJsonObject meta = obj["metadata"].toObject();
    qDebug() << "Name:" << name;
    qDebug() << "Hobbies:" << hobbies;
}
```

> ✅ 注意：`fromJson()` 接收的是 `QByteArray`，所以要用 `.toUtf8()`！

---



# ✅ 第三部分：Qt 中 QVariantMap 

## ✅ 1. QVariantMap 是什么？—— 它就是 Qt 的“轻量级 JSON 对象”

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| **`QVariant`**     | Qt 的“万能盒子”，能存 `int`, `double`, `QString`, `bool`, `QList`, `QMap`, 自定义对象等。它是所有类型的容器。 |
| **`QVariantMap`**  | 就是 `QMap<QString, QVariant>` 的别名。**它本质上就是一个键为 `QString`、值为任意类型的字典**。 |
| **`QVariantList`** | 就是 `QList<QVariant>` 的别名。代表 JSON 数组：`[ "a", 1, true, { ... } ]`。 |

### 💡 关键结论：

> ✅ **QVariantMap 就是 Qt 内部用来表示 JSON 对象的标准方式**。
> ✅ 你在 QML、QSettings、信号槽、数据库中看到的“动态结构”，背后基本都是 `QVariantMap`。
> ✅ 它不是 JSON，但**它能完美表达 JSON 对象结构** —— 因为 JSON 本身也是 key-value 字典。 

> 📌 所以你说得对：**QVariantMap 和 QJsonObject 很像** —— 它们都是“键值对容器”，只是一个是 Qt 原生的（QVariantMap），一个是 JSON 解析后的（QJsonObject）。 

## ✅ 2. QVariantMap 和 QJsonObject 转换

是 Qt 中 **最简洁、最官方、最推荐的** 把 `QMap<QString, T>` 转成 `QJsonObject` 的方式 —— **无需手动遍历，一行搞定**。

```C++
QMap<QString, QVariant> map; // 或者 QMap<QString, int>, QMap<QString, QString> 等

// 1. 将QMap转换为QVariantMap（Qt自动处理类型转换）
QVariantMap variantMap = map.toVariantMap();

// 2. 将QVariantMap转换为QJsonObject
return QJsonObject::fromVariantMap(variantMap);
```

```C++
QJsonObject json = ...;

// 1. 将QJsonObject转换为QVariantMap
QVariantMap variantMap = json.toVariantMap(); 

// 2. 将QVariantMap转换为QMap
QMap<QString, QVariant> map = variantMap.toStdMap(); 
```

## ✅ 2. QString 和 QJsonObject 转换

```C++
QString jsonObjectToString(const QJsonObject &obj) {
    QJsonDocument doc(obj);
	QString jsonStr = doc.toJson(QJsonDocument::Indented); // 美观格式
    // QString jsonStr = doc.toJson(QJsonDocument::Compact); // 美观格式
    return jsonStr;
}
```

```C++
QJsonObject stringToJsonObject(const QString &jsonStr) {
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        return {}; // 返回空对象，调用方可判断
    }
    return doc.object(); // 确保是对象，不是数组
}
```



#  ✅第四部分：实用技巧和最佳实践

| 场景               | 推荐做法                                                     |
| ------------------ | ------------------------------------------------------------ |
| **读取配置文件**   | 用 `QJsonDocument::fromJson(file.readAll())` + `isObject()` 检查 |
| **写入 JSON 文件** | `doc.toJson(...)` + `file.write(...)`                        |
| **处理嵌套结构**   | 递归使用 `.toObject()` / `.toArray()`                        |
| **安全访问字段**   | 总是判断 `.contains(key)` 或 `.isUndefined()`                |
| **避免崩溃**       | `QJsonValue::isUndefined()` 可检测不存在的键（比 `obj["xxx"]` 更安全） |
| **性能优化**       | 避免重复调用 `.toJson()`，缓存 `QJsonDocument`               |
| **中文支持**       | Qt 默认 UTF-8，无需额外处理                                  |

## ✅ 完整示例：读写 JSON 配置文件

```cpp
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

void saveConfig(const QString &filePath) {
    QJsonObject config;
    config["appName"] = "MyApp";
    config["version"] = 1.3;
    config["debug"] = true;

    QJsonArray themes;
    themes.append("dark");
    themes.append("light");
    config["themes"] = themes;

    QJsonDocument doc(config);
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
        qDebug() << "配置已保存：" << filePath;
    }
}

void loadConfig(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件：" << filePath;
        return;
    }

    QByteArray data = file.readAll();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "JSON 解析错误：" << parseError.errorString();
        return;
    }

    if (!doc.isObject()) {
        qWarning() << "JSON 根节点不是对象";
        return;
    }

    QJsonObject obj = doc.object();
    qDebug() << "应用名称：" << obj["appName"].toString();
    qDebug() << "版本：" << obj["version"].toDouble();
    qDebug() << "主题：" << obj["themes"].toArray();
}
```

---



# ✅ 总结：Qt JSON 核心类速查表

| 类              | 用途       | 类似 C++ 类型                                  | 如何创建                                  |
| --------------- | ---------- | ---------------------------------------------- | ----------------------------------------- |
| `QJsonValue`    | 万能值容器 | `std::variant<std::string, double, bool, ...>` | `QJsonValue("hello")`, `QJsonValue::Null` |
| `QJsonObject`   | 键值对对象 | `QMap<QString, QJsonValue>`                    | `QJsonObject{{"k", "v"}}`                 |
| `QJsonArray`    | 有序数组   | `QList<QJsonValue>`                            | `QJsonArray{1, 2, "hi"}`                  |
| `QJsonDocument` | 文档容器   | 封装 `QJsonObject` 或 `QJsonArray`             | `QJsonDocument(obj)` 或 `fromJson()`      |

| 操作           | 方法                                                 |
| -------------- | ---------------------------------------------------- |
| 序列化为字符串 | `doc.toJson(QJsonDocument::Indented)`                |
| 从字符串解析   | `QJsonDocument::fromJson(jsonStr.toUtf8())`          |
| 检查类型       | `.isString()`, `.isObject()`, `.isArray()`           |
| 转换为基本类型 | `.toString()`, `.toDouble()`, `.toBool()`            |
| 遍历对象       | `for (auto it = obj.begin(); it != obj.end(); ++it)` |
| 遍历数组       | `for (const auto &val : array)`                      |

---

