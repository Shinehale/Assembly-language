# 数据结构笔记总结 

​		——by 知乎

## **一、数据结构绪论**

### **数据结构的基本概念**

- 数据结构是一门研究非数值计算的程序设计问题中，计算机的操作对象以及它们之间的关系和操作的学科。
- 数据元素是数据的基本单位，在计算机程序中通常作为一个整体进行考虑和处理。
- 数据结构包含三个方面的含义：                                       

![img](https://pic2.zhimg.com/v2-07bfa931348a5e0f453f2897111cde65_b.jpg)

- 逻辑结构：

![img](https://pic1.zhimg.com/v2-67422d086f8325df4da74c70f4092e98_b.jpg)

- 物理结构：数据的逻辑结构在计算机中的表示，称此为物理结构，或称存储结构。                                                                                                    

![img](https://pic4.zhimg.com/v2-313aca63d8026554b8aa54bb779b8ed7_b.jpg)

![img](https://pic3.zhimg.com/v2-d6aa238b9019852e39685d50e46ccd7e_b.jpg)

- 数据类型：一个值的集合以及定义在这个值集上的一组操作的总称。

![img](https://pic3.zhimg.com/v2-dafe9fa237716a0282ab6b0d8a41aeaa_b.jpg)

- 抽象数据类型：通常由用户定义，用以表示应用问题的数据模型以及定义在该模型上的一组操作。                                                                                                     

![img](https://pic4.zhimg.com/v2-0aea97a0064d87736684facb51d1a7bb_b.jpg)

- 算法是描述计算机解决给定问题的操作过程，即为决解某一特定问题而由若干条指令组成的有穷序列。

![img](https://pic4.zhimg.com/v2-8acf1b8ccd6ff04473d0bc9e904cf4ef_b.jpg)

### 算法的效率分析

- 事后统计法：收集该算法实际的执行时间和实际占用空间的统计资料。
- 事前分析估算法：在算法运行之前分析该算法的时间复杂度和空间复杂度，来判断算法的效率。
- 时间复杂度分析：                                                                                            

![img](https://pic1.zhimg.com/v2-908d4962568fef15335d30bec58e47b4_b.jpg)

![img](https://pic4.zhimg.com/v2-ae8a1f489ec672b23d4e8a20c79b9247_b.jpg)

![img](https://pic2.zhimg.com/v2-7041bb4dffb31fb337b759074273a251_b.jpg)

- 常见函数的时间复杂度按数量递增排列及增长率：                                                                                                                  

![img](https://pic3.zhimg.com/v2-2aed58857ffe85c71cbd16955318155e_b.jpg)

## 二、线性表

### 线性表的类型定义

- 线性表是n(n>0)个相同类型数据元素构成的有限序列，其中n为线性表的长度。

![img](https://pic4.zhimg.com/v2-3d298000b4f6e33c8aa11dfcf1940f33_b.jpg)

- 线性表的基本操作：                                                                                         

![img](https://pic3.zhimg.com/v2-5cc2bcd52d2644cdf8dc9fcdc722c2ce_b.jpg)

![img](https://pic1.zhimg.com/v2-4632549a9b499795f6c8ff0230bbf728_b.jpg)

### 线性表的顺序表示和实现

- 线性表的顺序存储结构：用一组地址连续的存储单元依次存储线性表的元素。

![img](https://pic1.zhimg.com/v2-388edc6deae96ba68aad04bb03dda7e4_b.jpg)

- 线性表的顺序存储，也成为向量存储，又可以说是一维数组存储。线性表中结点存放的物理顺序与逻辑顺序完全一致，它叫[向量存储](https://www.zhihu.com/search?q=%E5%90%91%E9%87%8F%E5%AD%98%E5%82%A8&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22article%22%2C%22sourceId%22%3A%22356047870%22%7D)。

![img](https://pic3.zhimg.com/v2-196c9909863cdfb930f7f231208ff196_b.jpg)

- 线性表顺序存储结构在插入或删除数据元素时比较繁琐，但是它比较适合存取数据元素。
- 线性表的插入操作：在第i个元素之前插入一个元素时，需将第n至第i（共n-i+1）个元素向后移动一个位置。                                                                                         

![img](https://pic2.zhimg.com/v2-92476273c6e989e2c7ee5c7888e8a585_b.jpg)

- 线性表的删除操作：删除第i个元素时需将从第i+1至第n（共n-i）个元素一次向前移动一个位置                                                                                                 

![img](https://pic4.zhimg.com/v2-6fe7742fa810cd5e76335ca97763c783_b.jpg)

### 线性表的链式表示和实现

- 用一组任意的存储单元（可能不连续）存储线性表的数据元素。
- 在链式存储结构中，每个存储结点不仅包含数据元素本身的信息，还必须包含每个元素之间逻辑关系的信息，即包含直接后继结点的地址信息（指针域）。

![img](https://pic1.zhimg.com/v2-189a8060f9b811eff5666564339fd620_b.jpg)

- 逻辑顺序与物理顺序有可能不一致；属顺序存取的存储结构，即存取每个元素必须从第一个元素开始遍历，直到找到需要访问的元素，所以所花时间不一定相等。                                                                                                                  

![img](https://pic4.zhimg.com/v2-46dba8149a5e89d3534ca8f7b1e45e67_b.jpg)

![img](https://pic3.zhimg.com/v2-ea205a362c153ea51793c05ef9037e06_b.jpg)

- 链表的创建方式                                                                                                

![img](https://pic4.zhimg.com/v2-46fea85644349f1ac44e153d100316a7_b.jpg)

- 结点类的定义：                                                                                                 

![img](https://pic3.zhimg.com/v2-e2ea9c980699ce5478cf1aa5b12f189e_b.jpg)

### 单链表的基本操作

- 插入方式——头插法：                                                                                        

![img](https://pic3.zhimg.com/v2-aef6fb70ba86d5f0d1c334bd3e35ead2_b.jpg)

- 插入方式——尾插法：                                                                                            

![img](https://pic3.zhimg.com/v2-7b2eb6ec4c4afc5a38e143fe2858ad56_b.jpg)

- 查找运算——按序号查找：在链表中，即使知道被访问结点的序号i，也不能像顺序表中那么直接按序号i访问结点，而只能从链表的头指针除法，顺着链域next逐个结点往下搜索，直至搜索到第i个结点为止。链表不是随机存取结构，只能顺序存取。                                                                                                                  

![img](https://pic1.zhimg.com/v2-8a6dc704741de67f5af3ed3b2498bfd8_b.jpg)

- 查找运算——按数值查找：                                                                                     

![img](https://pic2.zhimg.com/v2-5556b06d6943e623028a635ec83e4dfd_b.jpg)

- 删除结点：将被删除结点的前驱指针连接被删除结点的后继指针

![img](https://pic4.zhimg.com/v2-271421379bfbc66a11edded2efec4f3f_b.jpg)

### 循环链表

- 表中尾结点的指针域指向头结点，形成一个环。从表中任意一个点出发都可以找到表中其他的结点。                                                                                                 

![img](https://pic4.zhimg.com/v2-711bcd436a8d8a3d936115f5e9d94a93_b.jpg)

- 循环链表的操作和[线性链表](https://www.zhihu.com/search?q=%E7%BA%BF%E6%80%A7%E9%93%BE%E8%A1%A8&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22article%22%2C%22sourceId%22%3A%22356047870%22%7D)的操作基本一致，但循环链表中没有NULL指针，故遍历操作时，终止条件不再是判断p或p.next是否为空，而是判断他们是否等于某一指定指针，如头指针或尾指针。

### 双向链表

- 双向链表是在单链表的每个结点里再增加一个指向其直接前驱的指针域prior。这样就形成了链表中有两个方向不同的链，故称为双向链表。

![img](https://pic1.zhimg.com/v2-621913a57aee74643bc1f802e8277900_b.jpg)

- 双线链表——头插法：                                                                                        

![img](https://pic1.zhimg.com/v2-041979b4cc9207654471910437d99b68_b.jpg)

- 双向链表——尾插法：                                                                                          

![img](https://pic2.zhimg.com/v2-a1d1250730ebc633905d2d2f98a539fd_b.jpg)

![img](https://pic4.zhimg.com/v2-dd768ec6c7cf2fd3d4dc067bb28af257_b.jpg)

- 插入操作

![img](https://pic3.zhimg.com/v2-867cc4cebca6dfe73c6c4660d11281da_b.jpg)

## 三、栈和队列

### 栈的概念

- 栈是限制在表的一端进行插入和删除运算的线性表，通常称插入、删除的这一端为栈顶，另一端为栈底。当表中没有元素时成为空栈。

![img](https://pic3.zhimg.com/v2-d5091c84f3bb17c3a3f80b9299e5a712_b.jpg)

- 栈的进出顺序判断：                                                                                    

![img](https://pic2.zhimg.com/v2-08c65046288af6eec904c99bac9b3521_b.jpg)

- 栈的基本操作：                                                                                                   

![img](https://pic2.zhimg.com/v2-2f3ead4f984573e74a42ec2ca150ed8d_b.jpg)

### 顺序栈

- 顺序栈利用一组地址连续的存储单元依次存放自栈底到栈顶的数据元素，同时由于栈的操作的特殊性，还必须附设一个位置指针top来动态地指示栈顶元素的顺序栈中的位置。通常以top=0表示空栈。                                                           

![img](https://pic1.zhimg.com/v2-5573d1c0ae9d45f6e842b65b213ea768_b.jpg)

![img](https://pic2.zhimg.com/v2-3d1329ee06a8af52e0e13fed06752e61_b.jpg)

- 顺序栈的基本运算：                                                                                                 

![img](https://pic4.zhimg.com/v2-46c3c361da816a3731d362a90ba31c5b_b.jpg)

![img](https://pic2.zhimg.com/v2-df835b40632839a2fe21412dc758ff61_b.jpg)

### 链栈

采用链表作为存储结构实现的栈。为便于操作，采用带头结点的单链表实现栈。因为栈的插入和删除操作仅限制在表头位置进行，所以链表的表头指针就作为栈顶指针。                                                                                                       

![img](https://pic2.zhimg.com/v2-741400706272320f63a07ff56f7a2e39_b.jpg)

### 顺序栈和链式栈的比较

实现链式栈和顺序栈的操作都是需要常数时间，即时间复杂度为O（1），主要从空间和时间两个方面考虑。初始时，顺序堆栈必须说明一个固定的长度，当堆栈不够满时，造成一些空间的浪费，而链式堆栈的长度可变则使长度不需要预先设定，相对比较节省空间，但是在每个节点中设置了一个指针域，从而产生了结构开销。

### 队列的概念

- 队列是一种先进先出的线性表，它只允许在表的一端进行插入，而在另一端删除元素。在队列中，允许插入数据一端成为队尾（rear），允许删除的那一端称为队头（front）。                                                                                    

![img](https://pic3.zhimg.com/v2-d46aea143363ba5c029c698aa3b780ce_b.jpg)

- 队列的基本操作：                                                                                       

![img](https://pic1.zhimg.com/v2-d70af15008ff1a2670561fa899bffff4_b.jpg)

![img](https://pic4.zhimg.com/v2-e15fd358174b0a3ce0cceadc0e0071bf_b.jpg)

### 顺序队列

- 顺序队列利用一组地址连续的存储单元依次存放自队首到队尾的数据元素，同时由于队的操作的特殊性，还必须附两个位置指针front和rear来动态地指示队首元素和队尾元素在顺序队列中的位置。通常front=rear表示空队列。

![img](https://pic1.zhimg.com/v2-59480682f50923d591333d0f0de66a14_b.jpg)

- 队列同堆栈一样也有上溢和下溢现象。以外，队列中还存在“假溢出”现象。所谓“假溢出”是指在入队和出队操作中，头尾指针不断增加而不减小或只减小而不增加，致使被删除元素的空间无法重新利用，最后造成队列中有空闲空间，但是不能够插入元素，也不能够删除元素的现象。

### 链式队列

采用链表作为存储结构实现的队列。为便于操作，采用带头结点的单链表实现队列。因为队列的插入和删除操作位置不同，所以链表需要设置表头指针和表尾指针分别指队首和队尾。

### 循环队列

- 假设向量的空间是m,只要在入出队列时，将队首和队尾的指针对m做求模运算即可实现队首和队尾指针的循环，即队首和队尾指针的取值范围是0到m-1之间。

![img](https://pic1.zhimg.com/v2-afcc91bf4a024b52a5d5cd1c05b11948_b.jpg)

![img](https://pic1.zhimg.com/v2-7ddabab9f742b2c3123c8b554c2bdf54_b.jpg)

![img](https://pic4.zhimg.com/v2-ef1b6a08a9ea8339529c8d5b3d0b70db_b.jpg)

- 判断队空和队满的方法                                                                                 

![img](https://pic2.zhimg.com/v2-f95d173ae01a4e6c2ce19aa1dc8f4bb1_b.jpg)

![img](https://pic3.zhimg.com/v2-030e5698e1f15ff3c169b1d25ee581b6_b.jpg)

## 四、数组和广义表

### 数组的定义

- 数组是我们熟悉的数据类型，数组中各元素具有统一的类型，并且数组元素的下标一般具有固定的上界和下界，因此，数组的处理比其它复杂的结构更为简单。
- 任何数组A都可以看作一个线性表。数组维数确定后，数据元素个数和元素之间的关系不再发生改变，适合顺序存储。
- 数组的基本操作                                                                                                 

![img](https://pic4.zhimg.com/v2-09ad2d1b7726cceec9edf10cef951fcb_b.jpg)

### 数组的顺序表示和实现

- 行优先顺序                                                                                                

![img](https://pic3.zhimg.com/v2-c5f509ba99249451c5bdc079beb843ee_b.jpg)

- 列优先顺序                                                                                                           

![img](https://pic3.zhimg.com/v2-ff97b41170c164359bedb08d56df9232_b.jpg)

### 矩阵的压缩存储

- 有些特殊矩阵，非零元素呈某种规律分布或者矩阵中出现大量的零元素的情况下，会占用许多单元去存储重复的非零元素或零元素，这对高阶矩阵会造成极大的浪费，为了节省存储空间，对这类矩阵进行压缩存储——即为多个相同的非零元素只分配一个存储空间；对零元素不分配空间。
- 特殊矩阵：所谓特殊矩阵是指非零元素或零元素的分布有一定规律的矩阵，如对称矩阵、三角矩阵、对角矩阵等等。                                                                     

![img](https://pic1.zhimg.com/v2-097b7d4f32bf6362978180317a67f760_b.jpg)

### 对称矩阵

![img](https://pic3.zhimg.com/v2-3524e6e2fabc998fca223b2e8103be92_b.jpg)

- 对称矩阵中元素关于主对角线对称，故只要存储矩阵中上三角或下三角中的元素，让每两个对称的元素共享一个存储空间，这样能节约近一半的存储空间。
- n2 个元素可以压缩到 n（n+1）/2个空间中。                                                   

![img](https://pic2.zhimg.com/v2-71bd76abde0630e076018b4cc9813295_b.jpg)

![img](https://pic4.zhimg.com/v2-4f64babba980661101c860292051b41b_b.jpg)

### 三角矩阵

- 以主对角线划分，三角矩阵有上三角和下三角两种。上三角矩阵它的下三角中的元素均为常数。下三角矩阵正好相反，它的主对角线上方均为常数。

![img](https://pic1.zhimg.com/v2-e59c370bf8167372c1a63b15dc376f7c_b.jpg)

![img](https://pic3.zhimg.com/v2-f149aa0d8def82ff2bc7a70b06ffa902_b.jpg)

![img](https://pic2.zhimg.com/v2-b51cd6229e3b75260bdf8058d1b03761_b.jpg)

### 稀疏矩阵

![img](https://pic4.zhimg.com/v2-fe2cb246b9153b00ece2b3d37e669a17_b.jpg)

除了记录非零元素的值之外，还必须同时几下它所在的行和列的位置。稀疏矩阵的存储方法一般有三种：三元组法、行逻辑连接顺序表和十字链表法。

![img](https://pic3.zhimg.com/v2-c264b3477ac072cd03fac04592f78032_b.jpg)

### 广义表

- 是由零个或多个原子或子表组成的优先序列，是线性表的推广。

![img](https://pic3.zhimg.com/v2-c15b59df68a00259090e50db09501cba_b.jpg)

![img](https://pic2.zhimg.com/v2-3c0d469afa97b78429961f4b228c6339_b.jpg)

![img](https://pic4.zhimg.com/v2-5f962101334171d06ecbbcea4f4c0bbb_b.jpg)

![img](https://pic4.zhimg.com/v2-348dcd05ae84ca4cb9981553605da917_b.jpg)

![img](https://pic1.zhimg.com/v2-a4f40a1d04e1b423a7560b627f8f1038_b.jpg)

![img](https://pic4.zhimg.com/v2-1fad89f6d6336f99549529e20be1d90b_b.jpg)

![img](https://pic4.zhimg.com/v2-c4f0b14a987da1643a163604e31d1a63_b.jpg)

### 广义表的存储结构

- 广义表中的数据元素可以具有不同的结构，因此，难以用顺序存储结构表示，通常采用链式存储结构，每个数据元素可用一个节点表示。由于广义表中有两种数据元素，因此需要有两种结构的节点——一种是表结点，一种是原子结点。
- 表结点由三个域组成：标志域、指示表头的指针的指针域和指示表尾的指针域；而原子域只需两个域：标志域和值域。                                                  

![img](https://pic2.zhimg.com/v2-f9dcdb97748c12b8406aa02d4dd1c221_b.jpg)

![img](https://pic4.zhimg.com/v2-b05604ca687147e7596f17610ed8ade7_b.jpg)

- 表结点由三个域组成：标志域、指示表头的指针域和指向下一个元素的指针；原子结点的三个域为：标志域、值域和指向下一个元素的指针。

![img](https://pic4.zhimg.com/v2-9b820d3da70078490e68019778fd9ecf_b.jpg)

![img](https://pic2.zhimg.com/v2-46328ccca1e8cdbd19180ea3c9d13001_b.jpg)

## 五、树

### 树的定义

![img](https://pic2.zhimg.com/v2-89bec5d9f147e731b57c467f7c4a04ed_b.jpg)

- 树的逻辑表示：树形表示法、文氏图表示法、凹入表示法、括号表示法。

![img](https://pic2.zhimg.com/v2-569b75211a6f368156d5a4802ed9d995_b.jpg)

![img](https://pic1.zhimg.com/v2-d96a77305c0f9d4f1aef885e388c5e4c_b.jpg)

![img](https://pic1.zhimg.com/v2-6b292b56c8f8ee9c02360b4a46c127cc_b.jpg)

![img](https://pic4.zhimg.com/v2-d1d20d6bdbcfd07aecce409dff520863_b.jpg)

- 结点：表示树中的元素，包括数据项及若干指向其子树的分支。
- 结点的度：结点拥有的子树树；树的度：一棵树中最大的结点度数

![img](https://pic2.zhimg.com/v2-bb466b5d26ee92abfb9ba9462ee82dcd_b.jpg)

- 叶子结点：度为0的结点；分支结点：度不为0的结点；孩子：结点子树的根称为该结点的孩子；双亲：孩子结点的上层结点叫该结点的双亲；兄弟：同一双亲的孩子。
- 深度：树中结点的最大层次数。                                                               

![img](https://pic2.zhimg.com/v2-9638df1cce39e8e667e525f67d522b39_b.jpg)

- 有序树：树中各结点的子树从左至右是有次序的，不能互换。否则称为无序树。

### 树的性质

- 树中的结点数等于所有结点的度数加1。

![img](https://pic4.zhimg.com/v2-410f23c6c5a0d63c33341718a6b9ec87_b.jpg)

- 度为m的树中第i层上至多有mi-1 个结点（i>=1）。    

![img](https://pic2.zhimg.com/v2-07fc76e90f6eba5c81e202f82720da09_b.jpg)

![img](https://pic3.zhimg.com/v2-e0513e95e8551c2336e2d1b6aa203d8e_b.jpg)

![img](https://pic4.zhimg.com/v2-d722c9262e4568f8459bb1b36a4d0ccb_b.jpg)

### [二叉树](https://www.zhihu.com/search?q=%E4%BA%8C%E5%8F%89%E6%A0%91&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22article%22%2C%22sourceId%22%3A%22356047870%22%7D)的概念

![img](https://pic4.zhimg.com/v2-9e6b96511bba7e0bfc61c741d6df49bf_b.jpg)

- 满二叉树：定义——一棵深度为k且具有2k-1个结点的二叉树。特点——每一层上的结点数都是最大结点数。
- 完全二叉树：定义——深度为k，有n个结点的二叉树当且仅当其每一个结点都与深度为k的满二叉树中编号从1至n的结点一一对应时，称为完全二叉树。

### 二叉树的性质

![img](https://pic3.zhimg.com/v2-ab880b7cd2a935d7c2bcb52fc9384462_b.jpg)

- 二叉树的第i层上至多有2i-1(i>=1)个结点。
- 深度为K的二叉树至多有2k-1个结点。
- 对任何一棵二叉树T，如果其叶子数为n0，度为2的结点数为n2，则n0=n2+1。

![img](https://pic3.zhimg.com/v2-4fa18c09ccd8980f4fd61bc953e8a7c6_b.jpg)

![img](https://pic3.zhimg.com/v2-a12de4b3a2f7def6d5236ca36806ac2e_b.jpg)

![img](https://pic4.zhimg.com/v2-e71d3acbf1eae570bd56f79a05dd4f67_b.jpg)

- 一个有n个结点的完全二叉树，编号最大的分支结点的编号是

![img](https://pic4.zhimg.com/v2-e315fe13a160309d99f05332d5f1eae3_b.jpg)

- 一个有n个结点的完全二叉树，n0的个数是不小于n/2的最小整数。

### 二叉树的存储结构

- 用一组连续的存储单元存储二叉树的数据元素。在存储之前对二叉树的所有结点安排一个适当的序列，使得结点在这个序列中的相互位置能反应出结点之间的逻辑关系。                                                                                                     

![img](https://pic1.zhimg.com/v2-bfa6c12941657481f9a824c8ba6792d4_b.jpg)

- 特点：结点间关系蕴含在其存储位置中；浪费空间，适于存满二叉树和完全二叉树。

### 二叉树的链式存储结构

- 用一个链表来存储一棵二叉树，二叉树中每一个结点用链表中的一个链结点来存储。                                                                                                   

![img](https://pic2.zhimg.com/v2-cfd1a60b381ed63552fd1494e2801cc9_b.jpg)

![img](https://pic3.zhimg.com/v2-32826d965d82aef69b2d6b2de093e286_b.jpg)

![img](https://pic1.zhimg.com/v2-3fb7b01a361016edc19cdb4db44df68c_b.jpg)

### 遍历二叉树

- 遍历方法：                                                                                                    

![img](https://pic4.zhimg.com/v2-45166f01b1713990693d917e164e57a7_b.jpg)

![img](https://pic1.zhimg.com/v2-158f362ebf57930bb7424b65243c6220_b.jpg)

- 利用遍历结果确定二叉树：                                                                         

![img](https://pic1.zhimg.com/v2-4a30ec8edf854f6f536213fa8b856f54_b.jpg)

- 先序遍历算法：

```
//先序遍历递归算法
void preorder(Tree t){
    if(t==null)
        return;
    visit(t);
    preorder(t.left());
    preorder(t.right());
}
 
//先序遍历非递归算法
void PreOrderUnrec(Bitree t)
{
    //创建栈来存放树的结点
    SqStack s;
    StackInit(s);
    p=t;
    
    while (p!=null || !StackEmpty(s))
    {
        while (p!=null)             //遍历左子树
        {
            visite(p->data);
            push(s,p);
            p=p->lchild;       
        }//endwhile
        
        if (!StackEmpty(s))         //通过下一次循环中的内嵌while实现右子树遍历
        {
            p=pop(s);
            p=p->rchild;        
        }//endif
                
    }//endwhile 
    
}//PreOrderUnrec
中序遍历算法：
 
//中序遍历递归算法
void inorder(Tree t){
    if(t==null)
        return;
    inorder(t.left());
    visit(t);
    inorder(t.right());
}
 
void InOrderUnrec(Bitree t)
{
    //创建栈来存放树的结点
    SqStack s;
    StackInit(s);
    p=t;
    
    while (p!=null || !StackEmpty(s))
    {
        while (p!=null)             //遍历左子树
        {
            push(s,p);
            p=p->lchild;       
        }//endwhile
        
        if (!StackEmpty(s))         //通过下一次循环中的内嵌while实现右子树遍历
        {
            p=pop(s);
            visite(p->data);        //访问根节点
            p=p->rchild;        
        }//endif
                
    }//endwhile 
    
}//InOrderUnrec
后序遍历算法：
 
后序遍历递归算法
void inorder(Tree t){
    if(t==null)
        return;
    inorder(t.left());
    inorder(t.right());
    visit(t);
}
 
//后序遍历非递归算法
对于任一结点P，将其入栈，然后沿其左子树一直往下搜索，直到搜索到没有左孩子的结点，此时该结点出现在栈顶，但是此时不能将其出栈并访问，因此其右孩子还为被访问。所以接下来按照相同的规则对其右子树进行相同的处理，当访问完其右孩子时，该结点又出现在栈顶，此时可以将其出栈并访问。这样就保证了正确的访问顺序。可以看出，在这个过程中，每个结点都两次出现在栈顶，只有在第二次出现在栈顶时，才能访问它。因此需要多设置一个变量标识该结点是否是第一次出现在栈顶。
void postOrder2(BinTree *root)    //非递归后序遍历
{
    stack<BTNode*> s;
    BinTree *p=root;
    BTNode *temp;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)              //沿左子树一直往下搜索，直至出现没有左子树的结点 
        {
            BTNode *btn=(BTNode *)malloc(sizeof(BTNode));
            btn->btnode=p;
            btn->isFirst=true;
            s.push(btn);
            p=p->lchild;
        }
        if(!s.empty())
        {
            temp=s.top();
            s.pop();
            if(temp->isFirst==true)     //表示是第一次出现在栈顶 
             {
                temp->isFirst=false;
                s.push(temp);
                p=temp->btnode->rchild;    
            }
            else                        //第二次出现在栈顶 
             {
                cout<<temp->btnode->data<<" ";
                p=NULL;
            }
        }
    }    
} 
```

### 线索二叉树

- 利用二叉链表的空指针域，建立指向该结点的前驱/后继结点的指针，方便二叉树的线性化使用。                                                                                     

![img](https://pic1.zhimg.com/v2-fcafd439a830245230ba507e8fdb6f84_b.jpg)

- 对二叉链表以某种次序遍历使其变为线索二叉树的过程叫做线索化。有先序线索二叉树、中序线索二叉树（更实用）和后序线索二叉树三种。

![img](https://pic3.zhimg.com/v2-f7ca6a3bec6440be4810a3ca910b8866_b.jpg)

- 建立中序线索二叉树                                                                                

![img](https://pic2.zhimg.com/v2-364b6bca5c21b940bbe181fd3e884665_b.jpg)

![img](https://pic2.zhimg.com/v2-c201b5978b9e75da1a63f316df0f1bf9_b.jpg)

![img](https://pic3.zhimg.com/v2-cffbafc4b8aca7338f8bb4c287ffef12_b.jpg)

![img](https://pic2.zhimg.com/v2-5c722411aa1dc1546c8d38f845cf70f9_b.jpg)

![img](https://pic3.zhimg.com/v2-dd2c3b5a25db448f7e14c7c838117caa_b.jpg)

![img](https://pic1.zhimg.com/v2-d093d7e95f9363e3a0b5d8ee4ed66218_b.jpg)

### 树的存储结构

- 双亲表示法：用一组连续空间存储树的结点，每个节点包含两个域——数据域用来存放结点本身信息，双亲域用来指示本结点的双亲结点在数组中位置。

![img](https://pic1.zhimg.com/v2-acebcee1f04847bf2cddcfca3ca8472c_b.jpg)

孩子表示法：采用孩子链表，每个结点的孩子结点用单链表存储，再用含n个元素的结构数组指向每个孩子链表。                                                             

![img](https://pic4.zhimg.com/v2-7e054cf57b7ad311a6a62ae651c361d7_b.jpg)

![img](https://pic4.zhimg.com/v2-73b3b4886c0b3c16bea791a35933da7f_b.jpg)

- 孩子兄弟表示法：用二叉链表作为树的存储结构。链表中结点的两个链域分为指向该结点的第一个孩子结点和下一个兄弟结点。                                                  

![img](https://pic4.zhimg.com/v2-cbfd61a20d4388e0aa0d0c85ae492303_b.jpg)

### 森林与二叉树的转换

- 将树转换为二叉树                                                                                     

![img](https://pic3.zhimg.com/v2-89896a608bc97dd7b02959a95479239a_b.jpg)

![img](https://pic3.zhimg.com/v2-4a40b13ded1ab09561aa3194cdf62d56_b.jpg)

- 将二叉树转换为树：                                                                                 

![img](https://pic4.zhimg.com/v2-75335b40b49c565d443fd0f254dcd997_b.jpg)

![img](https://pic2.zhimg.com/v2-7340f665e2a76030dac5f069441768f9_b.jpg)

- 森林转换成二叉树：                                                                                                 

![img](https://pic2.zhimg.com/v2-2d902b482c9bfc3c4023f93975f55c35_b.jpg)

![img](https://pic1.zhimg.com/v2-7b7e6f9284420f7179c0499210a168f4_b.jpg)

- 二叉树转换成森林                                                                                    

![img](https://pic3.zhimg.com/v2-89b579149293c7614d1efb2a23b875d2_b.jpg)

![img](https://pic4.zhimg.com/v2-b5c8c9056fd9e649c35ccc8ffffa9293_b.jpg)

### 哈夫曼树

- 结点的权及带权路径长度：若将树中结点赋给一个有着某种含义的数值，则这个数值称为该结点的权。结点的带权路径长度为：从根节点到该结点之间的路径长度与该结点的权的乘积。                                                                          

![img](https://pic2.zhimg.com/v2-39a2fe8f528da3d30d8bfe1b3416fcb1_b.jpg)

![img](https://pic3.zhimg.com/v2-cdb70ddaa4bd9adabe55b66918a6576e_b.jpg)

- 在一棵二叉树中，若带权路径长度达到最小，称这样的二叉树为最优二叉树，也称哈夫曼树。                                                                                          

![img](https://pic4.zhimg.com/v2-1384c855eb90ba3b2a075a088484a777_b.jpg)

## 六、图

### 图的概念

- 图是一种较线性表和树更为复杂的数据结构，在图形结构中，结点之间关系可以是任意的，图中任意两个数据元素之间都可能相关。

![img](https://pic3.zhimg.com/v2-565af1c82a37bbcaa40662de517e02a6_b.jpg)

- [有向图](https://www.zhihu.com/search?q=%E6%9C%89%E5%90%91%E5%9B%BE&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22article%22%2C%22sourceId%22%3A%22356047870%22%7D)和无向图                                                                                                         

![img](https://pic4.zhimg.com/v2-b0fc1e3af056ad05d821c849fcf0c933_b.jpg)

- 若无向图中的每两个顶点之间都存在着一条边，则称该无向图称作完全无向图；显然完全无向图中包含着e=n(n-1)/2条边。若有无向图中的每两个顶点之间都存在方向相反的两条边，则称该有向图称作完全有向图；显然完全有向图中包含有e=n(n-1)条边。                                                                               

![img](https://pic3.zhimg.com/v2-ebc008a72d0346aa30c53d17521261fe_b.jpg)

- 与图的边或弧相关的数叫做权，带权的图称为网。                                             

![img](https://pic2.zhimg.com/v2-da05e5b91fcbdee274a80f260a1bffd9_b.jpg)

![img](https://pic4.zhimg.com/v2-932a6ee9d7e226a147fbd162fbb3171b_b.jpg)

![img](https://pic1.zhimg.com/v2-ff9820661a85440a7090d1d963ba4a64_b.jpg)

- 对于有向图而言，度又分为出度和入度。顶点的出度——以顶点v为弧尾的弧的数目；顶点的入度——以顶点v为弧头的弧的数目；顶点的度为该顶点的出度和入度的和。                                                                                                         

![img](https://pic4.zhimg.com/v2-f1f37e5823ded1ab82797683fc57929f_b.jpg)

![img](https://pic3.zhimg.com/v2-e0721ff4266b55f007c4dcf45c9ad5c2_b.jpg)

- 在无向图G中，如果从顶点v到顶点w存在路径，则称v到w是连通的。若图G中任意两个顶点之间都有路径相通，则称为连通图。
- 若无向图为非连通图，则图中各个极大连通子图称作此图的连通分量。任何连通图的连通分量只有一个，即本身，而非连通图则有多个连通分量。

![img](https://pic1.zhimg.com/v2-b6004ac08f1ea0edb36e74eeddc9a004_b.jpg)

- 在有向图中，若任意两个顶点之间都存在一条有向路径，则称此有向图为强连通图。
- 若有向图为非强连通图，其各个强连通子图称为它的强连通分量。

![img](https://pic3.zhimg.com/v2-898b62b1e07d4cbf7d62d35b407f726a_b.jpg)

### 图的存储结构——邻接矩阵

- 邻接矩阵是表示顶点之间相邻关系的矩阵。                                                        

![img](https://pic3.zhimg.com/v2-c2b9e203ed113106d9a72d58f13ff0d6_b.jpg)

- 无向图的邻接矩阵：                                                                                        

![img](https://pic1.zhimg.com/v2-5d251e1f73050127ca348344c439d340_b.jpg)

- 有向图的邻接矩阵：                                                                                      

![img](https://pic2.zhimg.com/v2-9802eb430abc1345021b4f56a7c6a639_b.jpg)

- 网的邻接矩阵：                                                                                                         

![img](https://pic1.zhimg.com/v2-26beb2744798de6279592111d840ff20_b.jpg)

![img](https://pic3.zhimg.com/v2-1eded28a6c9d6129be6f5a84a89bb5b6_b.jpg)

![img](https://pic4.zhimg.com/v2-3d9723493cb92b1dceea6fd8d4c6f47f_b.jpg)

### 图的存储结构——邻接表

- 邻接表存储方法是一种顺序分配与链式分配相结合的存储方法。它包括两部分：一部分是单链表，用来存放边的信息；另一部分是数组，主要用来存放顶点本身的数据信息。                                                                                                  

![img](https://pic4.zhimg.com/v2-5e2c2aebe0deb21f83dcd9f0a62498af_b.jpg)

- 无向图邻接表：                                                                                       

![img](https://pic3.zhimg.com/v2-b754f200e69ca0e72db6c1a0b676d5b2_b.jpg)

- 有向图的邻接表：                                                                                           

![img](https://pic2.zhimg.com/v2-e7353bb409a39f36f35412576ed8579d_b.jpg)

![img](https://pic4.zhimg.com/v2-318825cc62d124831c26685ed3ca8933_b.jpg)

### 图的存储结构——十字链表

- 十字链表是有向图的另一种链式存储结构。可以看成是将有向图的邻接表和逆邻接表结合起来得到的一种链表。在十字链表中，每条弧和每个顶点分别对应着一个结点。                                                                                              

![img](https://pic4.zhimg.com/v2-19dac4222b10899605f87c57917c2357_b.jpg)

![img](https://pic4.zhimg.com/v2-20eb2071edd11a3a5fb6c7a331c8f0db_b.jpg)

![img](https://pic4.zhimg.com/v2-182212d4ddd5eba45b9abf1553f8eeff_b.jpg)

### 图的存储结构——邻接多重表

- 邻接多重表是无向图的另一种链式存储结构。邻接多重表和十字链表一样，每条边和每个顶点分别对应着一个结点。                                                     

![img](https://pic4.zhimg.com/v2-73eed0b789590d6c650f0f9be3beb0fb_b.jpg)

![img](https://pic2.zhimg.com/v2-248cfa705e298ded89418718a9846add_b.jpg)

![img](https://pic2.zhimg.com/v2-e6e4bfead2aeb45a7b232c977beed62d_b.jpg)

### 图的遍历

- 从图中某个顶点出发游历图，访遍图中其余顶点，并且使图中的每个顶点仅被访问一次的过程
- 根据搜索方法的不同，图的遍历有两种：深度优先搜索（DFS）和广度优先搜索（WFS）。

### 深度优先搜索

![img](https://pic2.zhimg.com/v2-7a3d824439a5b9164db941d2c94d4aa5_b.jpg)

![img](https://pic4.zhimg.com/v2-b4eaa724705ddb6c39c163dea5771c73_b.jpg)

![img](https://pic1.zhimg.com/v2-b96933846f2342a41c05d76dcd964a74_b.jpg)

- 连通图深度优先搜索的算法：                                                                                         

![img](https://pic2.zhimg.com/v2-0424337ad0155df6d7cb3b16fa5f9811_b.jpg)

![img](https://pic1.zhimg.com/v2-7cec0693ed949aa5db677cb18a897d54_b.jpg)

### 广度优先搜索

![img](https://pic1.zhimg.com/v2-88436415aa05c7666ca7e24b68b7e884_b.jpg)

- 广度优先搜索是一种分层的搜索过程，每向前走一步可能访问一批顶点，不像深度优先搜索那样有回退的情况。因此，广度优先搜索不是一个递归的过程，其算法也不是递归的。                                                                                          

![img](https://pic3.zhimg.com/v2-5c38f41c4b6525a3f7725fb7aab52e6e_b.jpg)

- 连通图的广度优先搜索算法：                                                                         

![img](https://pic3.zhimg.com/v2-6b34a36b55c380c6307b9c7ccc674632_b.jpg)

- 非连通图广度优先搜索：                                                                                 

![img](https://pic1.zhimg.com/v2-38042047c903f7718522e1320a7f0924_b.jpg)

### 无向图的连通分量和生成树

- 连通图生成树：一个连通图的生成树是一个极小连通子图，它含有图中全部顶点，但只有构成一棵树的n-1条边。

![img](https://pic1.zhimg.com/v2-18a2e968aaa112328e30444c5a5df14c_b.jpg)

![img](https://pic3.zhimg.com/v2-4d0a225ec9d1287d9268b51da2a3e6da_b.jpg)

- 当无向图为非连通图时，从图中某一顶点除法，利用深度优先搜索算法或广度优先搜索算法不可能遍历到图中的所有顶点，只能访问到该顶点所在的极大连通子图的所有顶点，该极大连通子图称为无向图的一个连通分量。

![img](https://pic1.zhimg.com/v2-9a1669c14a23cfa1a3b323db06d2e684_b.jpg)

- 使用不同的遍历图的方法，可以得到不同的生成树；从不同的顶点出发，也可能得到不同的生成树。                                                                              

![img](https://pic4.zhimg.com/v2-0c91562b56802740bc0eec16e90036eb_b.jpg)

### 最小生成树

- 在连通网的众多生成树中，各边权值之和最小的生成树称为最小代价生成树，简称最小生成树。                                                                                  

![img](https://pic4.zhimg.com/v2-4b061381e87d81efcbd6730409ad78ab_b.jpg)

- 生成最小生成树算法——普里姆算法：                                                            

![img](https://pic4.zhimg.com/v2-2bf34f44fdcaa606edb4cddc6a9efc3b_b.jpg)

![img](https://pic3.zhimg.com/v2-cdbd914cf05baf30d749cd3399acf652_b.jpg)

- 生成最小生成树算法——克鲁斯卡尔算法：                                                     

![img](https://pic3.zhimg.com/v2-6eec2a13a886e486f09cd8be59fc5b7e_b.jpg)

![img](https://pic1.zhimg.com/v2-50f69c3dd2e4af536d50dc7f51f19b00_b.jpg)

### 有向无环图

- 一个无环的有向图称为有向无环图，简称DAG图。

![img](https://pic1.zhimg.com/v2-8a71f949bfc3b5ef659d25e4bc16be24_b.jpg)

### 拓扑排序

- 在一个有向图中，若用顶点表示活动，有向边表示活动间的先后关系，称该有向图叫做顶点表示活动的网络，简称AOV网。                                          

![img](https://pic3.zhimg.com/v2-cd6130fb4f03a2e589c39aaa9f9dc0aa_b.jpg)

- 按照有向图给出的次序关系，将图中顶点排成一个线性序列，对于有向图中没有限定次序关系的顶点，则可以人为加上任意的次序关系。由此所得顶点的线性序列成为拓扑有序序列。
- [拓扑排序](https://www.zhihu.com/search?q=%E6%8B%93%E6%89%91%E6%8E%92%E5%BA%8F&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22article%22%2C%22sourceId%22%3A%22356047870%22%7D)：由某个集合上的一个偏序（集合中仅有部分成员之间可以比较）得到该集合上的一个全序（集合中全体成员之间均可以比较）的操作称为拓扑排序。

![img](https://pic3.zhimg.com/v2-525d63865679b0c5597796af8db00daa_b.jpg)

- 拓扑排序的算法：                                                                                     

![img](https://pic2.zhimg.com/v2-66b1ee571f72e29926f7ac81f1d7a455_b.jpg)

![img](https://pic4.zhimg.com/v2-31a03c499e8a4c6ff5918e12a8427c3f_b.jpg)

![img](https://pic1.zhimg.com/v2-850375302f240f94b51b1f37e34df9f0_b.jpg)

### 关键路径

- 在一个有向图中，若用顶点表示事件，弧表示活动，权表示活动持续时间，称该有向图叫做边表示活动的网络，简称为AOE网。

![img](https://pic4.zhimg.com/v2-01a5370b8a97ad3f8481faa20e8ab563_b.jpg)

![img](https://pic1.zhimg.com/v2-6ea23892923da7aa515a7baf97d53f7c_b.jpg)

![img](https://pic4.zhimg.com/v2-a0647ebd6e070673cab51c21dc44326f_b.jpg)

![img](https://pic1.zhimg.com/v2-6266d16a2656e49c1c72ed5fa6e058b0_b.jpg)

![img](https://pic3.zhimg.com/v2-127eb9aee4af3ca40a3c5be03fb212f6_b.jpg)

![img](https://pic3.zhimg.com/v2-243c37778e45c7f36be9035920f9df7e_b.jpg)

![img](https://pic4.zhimg.com/v2-47b174e43604a738cdda6258014f3fe3_b.jpg)

![img](https://pic3.zhimg.com/v2-4620b8bb7033cf4c7ebe0b4628b8a6aa_b.jpg)

## 七、查找

### 概述

- 查找表：由同一类型的数据元素（或记录）构成的集合。

![img](https://pic4.zhimg.com/v2-5013242dc8e11050f2be919f7874736b_b.jpg)

![img](https://pic4.zhimg.com/v2-3ebc90e3e5e1bc31f3a8e68accf1ea1b_b.jpg)

![img](https://pic1.zhimg.com/v2-2f68f42770246a61568b989816e537ac_b.jpg)

### 静态查找表

- 静态查找是指在静态查找表上进行的查找操作，在查找表中满足条件的数据元素的存储位置或各种属性。静态查找表的查找算法主要有：                                

![img](https://pic4.zhimg.com/v2-aa0bcf0127a3f2e2eea1fe6377beb2ff_b.jpg)

- 顺序查找：从表的一端开始，顺序扫描线性表，依次将扫描到的关键字和给定值k进行比较，若当前扫描到的关键字与k相等，则查找成功；若扫描结束后，仍未找到关键字等于k的记录，则查找失败。                                                           

![img](https://pic3.zhimg.com/v2-f3562b387ec14edacad070169cbd19f6_b.jpg)

![img](https://pic2.zhimg.com/v2-605946f8172abf5f0316c61a8d08cc29_b.jpg)

- [折半查找](https://www.zhihu.com/search?q=%E6%8A%98%E5%8D%8A%E6%9F%A5%E6%89%BE&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22article%22%2C%22sourceId%22%3A%22356047870%22%7D)：对给定值k，逐步确定待查记录所在区间，每次将搜索空间减少一半，直到查找成功或失败为止。                                                                     

![img](https://pic1.zhimg.com/v2-0ff6d379e1a9feff5fd5bc098a92efb4_b.jpg)

![img](https://pic3.zhimg.com/v2-017252d075231658722611b56bdb637e_b.jpg)

![img](https://pic1.zhimg.com/v2-59f31f72bd266c751597d049ee8e3d2c_b.jpg)

![img](https://pic3.zhimg.com/v2-f8b2120971d4a03c3eb77999bfa9b28e_b.jpg)

- 分块查找：                                                                                                      

![img](https://pic2.zhimg.com/v2-273be6dd3c7a73cd7df161e6c6f2b841_b.jpg)

![img](https://pic2.zhimg.com/v2-b92284c31c7351bec4f37c6564c749ed_b.jpg)

### 动态查找表

表结构在查找过程中动态生成的这样一种查找表。实现动态查找方法：二叉排序树、平衡二叉树、B-树和B+树。

### 二叉排序树

- 定义：左子树的所有结点均小于根的值；右子树的所有节点均大于根的值；它的左右子树也分别为二叉排序树。                                                                       

![img](https://pic3.zhimg.com/v2-a6d5b7a19af79289526863e43fd866ba_b.jpg)

- 二叉排序树插入新结点的过程                                                    

![img](https://pic2.zhimg.com/v2-a5abd9717b616c92429099a8d5097415_b.jpg)

- 二叉排序树插入新节点递归算法：                                                                       

![img](https://pic4.zhimg.com/v2-736f8cb98694a799a74267bd20a89d8b_b.jpg)

![img](https://pic1.zhimg.com/v2-b9d04df7464bb91f79ab7a5c947925ec_b.jpg)

- 二叉排序树删除结点的算法：                                                                      

![img](https://pic1.zhimg.com/v2-4a109e794500190e850213e0cf027d3c_b.jpg)

![img](https://pic4.zhimg.com/v2-b57fd4d106a395adb1ba029b45246ef7_b.jpg)

- 二叉排序树查找算法分析：                                                                           

![img](https://pic4.zhimg.com/v2-b0b6d3905367135fb1584c224ed3e6df_b.jpg)

### 平衡二叉树

- 平衡二叉树又称为AVL树，设二叉树中结点的左子树和右子树的深度分别为HL和HR。                                                                                                              

![img](https://pic2.zhimg.com/v2-d830a17f2e7ac11ae59c5c0c2aeb1475_b.jpg)

![img](https://pic1.zhimg.com/v2-54c172d59fce29ce724eefcfa89d6640_b.jpg)

- 若在构造二叉排序树的同时，使其始终保持为AVL树，则此时的二叉排序树为平衡的二叉排序树。将一棵非平衡二叉排序树调整成平衡二叉排序树的“旋转”，分为：LL平衡旋转、RR平衡旋转、LR平衡旋转、RL平衡旋转。

![img](https://pic4.zhimg.com/v2-354bd6d15c2c0f7a2aa4c8192b529473_b.jpg)

![img](https://pic4.zhimg.com/v2-33fbb89147607aaef6a5d9046f72ad3f_b.jpg)

![img](https://pic4.zhimg.com/v2-bd4baba2f92ed0906f66ce8a20c8dd23_b.jpg)

![img](https://pic2.zhimg.com/v2-f5af39fc4823ef6e9caab7b2f060b801_b.jpg)

![img](https://pic3.zhimg.com/v2-49f71ff12f2fee38ff7e658e0bf262de_b.jpg)

![img](https://pic1.zhimg.com/v2-93ffc448eaa12f18d548cecc4ad1d160_b.jpg)

### B-树

- B-树又称基本B树或多路平衡查找树。它是构造大型文件系统索引结构的一种数据结构类型，适合在磁盘等直接存取设备上组织动态的查找表。

![img](https://pic3.zhimg.com/v2-5cebe8c793a33d433af155d0be6cb0fe_b.jpg)

![img](https://pic2.zhimg.com/v2-4ac66d90825dce34f91a7abdee6de351_b.jpg)

![img](https://pic4.zhimg.com/v2-23ffe0d1734ca0757cbd7b699a1a4c9b_b.jpg)

- 该公式包括没有任何关键字的叶子结点。
- B-树的查找算法思路：                                                                                        

![img](https://pic2.zhimg.com/v2-79e651a533ce3cdc9afcdfa248bda53d_b.jpg)

![img](https://pic3.zhimg.com/v2-05a6c89908dd5b56218967579db8ca4e_b.jpg)

- B-树的查找效率取决于以下两个因素：包含k的结点在B-树种所在的层数h；结点中ki的个数n。                                                                                                 

![img](https://pic2.zhimg.com/v2-93bd74dd2039ae10e0adb770e01122f9_b.jpg)

- B-树的生成：                                                                                              

![img](https://pic4.zhimg.com/v2-77f79022377831b77c2e739202a70c4b_b.jpg)

![img](https://pic4.zhimg.com/v2-d17db867beea2b1c52595e23bd9d7f9b_b.jpg)

- B-树的删除：                                                                                                    

![img](https://pic3.zhimg.com/v2-96dfbc2e25e6572337bd198b147fd64a_b.jpg)

### B+树

- B+树是B-树的变形，目的在于有效地组织文件的索引结构。
- m阶B+树与B-树的差异：                                                                                    

![img](https://pic1.zhimg.com/v2-9f3ec5ae8c5567e61e2a38ff87ddfbc4_b.jpg)

![img](https://pic4.zhimg.com/v2-4b49658a480bc793e48734c455322ca3_b.jpg)

- B+树种可以有两种查找方式：顺序查找——类似单链表的查找，直接在数据层进行查找。随机查找——类似B-树的查找，不同的是搜索到索引层的key与k相等时，还得继续搜索下去，直到数据层为止。

![img](https://pic4.zhimg.com/v2-b8de974aa1a5ab2c9f70eabbb2e88a9f_b.jpg)

### 哈希表

![img](https://pic2.zhimg.com/v2-b557271cd97f55ade3b94f6af1ac52e1_b.jpg)

- 哈希表，根据设定的[哈希函数](https://www.zhihu.com/search?q=%E5%93%88%E5%B8%8C%E5%87%BD%E6%95%B0&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22article%22%2C%22sourceId%22%3A%22356047870%22%7D)H（key）和处理冲突的方法将一组关键字key映射到一个有限的连续的地址集上，并以关键字key在地址集中的“像”作为记录在表中的存储位置，这种表便称为哈希表，这一映射过程称为哈希造表或散列，所得存储位置称哈希地址或散列地址。                   

![img](https://pic1.zhimg.com/v2-8369d17082aacc39eaab5abe873b3284_b.jpg)

- 将不同的关键码映射到同一个哈希地址上，该现象称为冲突。

### 哈希函数的构造方法

- 常用的哈希函数构造方法有：直接定址法、除留余数法、乘余取整法、数字分析法、平方取中法、折叠法、随机数法。
- 直接定址法：        

![img](https://pic1.zhimg.com/v2-e4849575ddc414257c6e2ed5de9999c0_b.jpg)

- 除留余数法：

![img](https://pic3.zhimg.com/v2-b9bfda64c1cba23987db18f0d4dd0ab6_b.jpg)

-  乘余取整法：    

![img](https://pic4.zhimg.com/v2-3b370c6ed7f560a2163865105f7440ab_b.jpg)

- 数字分析法：       

![img](https://pic3.zhimg.com/v2-b28f2a643fe27cd5f6c77421d9a724a2_b.jpg)

- 平方取中法：

![img](https://pic1.zhimg.com/v2-e0faddffc63c09bf33ed6a712fb1be40_b.jpg)

- 叠加法： 

![img](https://pic4.zhimg.com/v2-e032b99429b09ac21f35451a079cc743_b.jpg)

- 随机数法：

![img](https://pic4.zhimg.com/v2-31e65a286021ef6205abe5e23bfc7def_b.jpg)

### 处理冲突的方法

- 开放定址法、链地址法、再哈希法、建立一个公共溢出区
- 开放定址法：

![img](https://pic1.zhimg.com/v2-9ade5187387faf0316ecc24e51c855e8_b.jpg)

![img](https://pic2.zhimg.com/v2-a9d11d804119df752210ab361d2879b9_b.jpg)

![img](https://pic3.zhimg.com/v2-3c12e90f6a5c0d92ab1bad6ed3a8d8ea_b.jpg)

- 链地址法：

![img](https://pic1.zhimg.com/v2-e34a587ca376a080cc2e06b0aa586934_b.jpg)

![img](https://pic4.zhimg.com/v2-bfa2b7bc5b9b1fc5381bf9d076881f83_b.jpg)

- 再哈希法：    

![img](https://pic1.zhimg.com/v2-b7fb1a7f720688cd40d4c1e0ad4dbc58_b.jpg)

- 建立一个公共溢出区：                                                                                           

![img](https://pic1.zhimg.com/v2-77ff4f5f8a96ef92f45f330ef108911c_b.jpg)

### 红黑树

- 红黑树，一种二叉查找树，但在每个结点上增加一个存储位表示结点颜色，可以是Red或Black。通过对任何一条从根到叶子的路径上各个结点着色方式的限制，红黑树确保没有一条路径会比其他路径长出两倍，因而是接近平衡的。

![img](https://pic1.zhimg.com/v2-9e8eadb29de8691c0ced2da8c32181b0_b.jpg)

- 红黑树虽然本质上是一棵二叉查找树，但它在二叉查找树的基础上增加了着色和相关的性质使得红黑树相对平衡，从而保证了红黑树的查找、插入、删除的时间复杂度最坏为O(log n)。红黑树和AVL树的区别在于它使用颜色来标识结点的高度，它所追求的是局部平衡而不是AVL树中的非常严格的平衡。
- 红黑树的五个性质保证了红黑树的高度始终保持在logn:

![img](https://pic2.zhimg.com/v2-59790a5fcd0fa63fceb65d9e41a10709_b.jpg)

![img](https://pic4.zhimg.com/v2-9892e93ca4883953a567dfc486b08837_b.jpg)

- 红黑树的旋转操作：红黑树的旋转操作和AVL树一样，分为LL、RR、LR、RL四种旋转类型，差别在于旋转完成后改变的是结点的颜色，而不是平衡因子。

## 八、排序

### 排序概述

- 排序的分类：内部排序和外部排序（若待排序记录都在内存中，称为内部排序；若待排序记录一部分在内存，一部分在外存，则称为外部排序）。稳定排序和不稳定排序。       

![img](https://pic3.zhimg.com/v2-b4c3c797a5620f6bf4252bddbfde2f7a_b.jpg)

- 内部排序的算法：插入排序（希尔排序）、交换排序（快速排序）、选择排序（堆排序）、归并排序、基数排序。

### 插入排序

- 思想：每次将一个待排序的对象，按其关键码大小，插入到前面已经排好序的一组对象的适当位置上，直到对象全部插入为止。
- 具体实现算法：直接插入排序、折半插入排序、希尔排序
- 直接插入排序：  

![img](https://pic1.zhimg.com/v2-b14adba88ca336e7d4be471397ef0ac0_b.jpg)

![img](https://pic2.zhimg.com/v2-1426061199f769f10abc4af3bed1f491_b.jpg)

```
void InsertSort(int a[]){
    int i,j;
    //按照有小到大的顺序排序
    for(i=2;i<a.length;i++){
        //找到无序表的第一个位置
        if(a[i]<a[i-1]){
            a[0]=a[i];
            //将无序表依次向后移动
            for(j=i-1;a[0]<a[j];j--){
                a[j+1]=a[j];
            }
            //将数据插入相应位置
            a[j+1]=a[0];
        }
    }
}
该算法的时间复杂度是：O（n2）
```

![img](https://pic4.zhimg.com/v2-d78f8d022380eecc943016d4e4850427_b.jpg)

- 折半插入排序：                                                                                           

![img](https://pic2.zhimg.com/v2-a2e0ff965b4adfbfed32ff9e62759701_b.jpg)

```
void BInsertSort(int a[]){
    int i,j,high,low;
    for(i=2;i<a.length;i++){
        a[0]=a[i];      
        low=1;
        high=i-1;
        int min;
        while(low<=high){       //使用折半查找到插入的位置
            min=(high+low)/2;
            if(a[0]<a[min])
                high=min-1;
            else
                low=min+1;
        }
        for(j=i-1;j=>high+1;j++)    //插入的位置是在high位置之后
            a[j+1]=a[j];
        a[high+1]=a[0];
    }
}
```

![img](https://pic2.zhimg.com/v2-361e5056a41c19a0da3d7afa800d7c75_b.jpg)

- 希尔排序：

![img](https://pic4.zhimg.com/v2-3b3ba87f91a665fffa2423ea5ca45303_b.jpg)

![img](https://pic1.zhimg.com/v2-c5ece32bbccab146d279eb22bba26054_b.jpg)

从排序过程可以看出，希尔排序的一个特点是：子序列的构成不是简单地“逐段分割”，而是将相隔某个“增量”的记录组成一个子序列。

```
void SheelSort(int a[],int dx){
    //这是对直接插入排序的修改
    //dx表示增量
    //当j<=0时，插入位置已经找到
    int i,j;
    for(i=dx+1;i<a.length;i++){
        if(a[i]<a[i-dx]){
            a[0]=a[i];
            for(j=i-dx;j>0&&a[0]<a[j];j-=dx)
                a[j+dx]=a[j];
            a[j+dx]=a[0];
        }
    }
}
```

![img](https://pic2.zhimg.com/v2-7f770d2907e439b42042ed88c6eea845_b.jpg)

### 交换排序

- 两两比较待排序记录的关键码，如果发生逆序（即排列顺序与排序后次序正好相反），则交换之，直到所有记录都排好序为止。
- 冒泡排序：                                                                                                     

```
void bubbleSort(int a[]){
    int i,j;
    for(i=1;i<a.length-1;i++){
        for(j=1;j<a.length-i;j++){
            if(a[j]>a[j+1]){
                a[0]=a[j];
                a[j]=a[j+1];
                a[j+1]=a[0];
            }
        }
    }
}
```

![img](https://pic1.zhimg.com/v2-e645b040765473726c0029532f618f98_b.jpg)

- 快速排序：                                                                                                  

![img](https://pic2.zhimg.com/v2-02186906d89113f54b161b168a54aac5_b.jpg)

![img](https://pic1.zhimg.com/v2-304e1efdafd4bf06b267ff2c008f781c_b.jpg)

![img](https://pic2.zhimg.com/v2-ede0338c77f80a24db92a5fee83e39e5_b.jpg)

![img](https://pic2.zhimg.com/v2-ee9abac705d8a769c3daa6b4fbe87781_b.jpg)

```
void Partition(int a[],int low,int high){
    //这只是一趟快速排序的算法
    a[0]=a[low];
    while(low<high){
        //从高位往低位扫描，找到数值小于关键字的位置，与low位置交换
        while(low<high&&a[0]<=a[high])
            high--;
        a[low]=a[high];
        //从低位往高位扫描，找到数值大于关键字的位置，与high位置交换
        while(low<high&&a[low]<=a[0])
            low++;
        a[high]=a[low];
    }
    //最后将关键字放入数组中
    a[low]=a[0];
}
快速排序平均时间复杂度和最好时间复杂度为：O（log2n），最坏时间复杂度为O（n2）。
```

![img](https://pic2.zhimg.com/v2-1578fa8ac4f337eac48c9883649093fd_b.jpg)

### 选择排序

- 不断从待排记录序列中选出关键字最小的记录插入已排序记录序列的后面，直到n个记录全部插入已排序记录序列中。
- 简单选择排序： 

![img](https://pic3.zhimg.com/v2-49cd7755e2f7992df69daa038b31f6aa_b.jpg)

![img](https://pic2.zhimg.com/v2-d23e0d60b74208d22092e7f610a8e6e5_b.jpg)

![img](https://pic4.zhimg.com/v2-ff9293caaf5eddd04bf3e2e88e462323_b.jpg)

- 堆排序：借助于完全二叉树结构进行的排序，是一种树形选择排序。其特点是——在排序过程中，将R[1...N]看成是一棵完全二叉树的顺序存储结构，利用完全二叉树双亲结点和孩子结点之间的内在关系，在当前无序区中选择关键字最大（或最小）的记录。

![img](https://pic2.zhimg.com/v2-ceb600ce9bd9be42de54038ae88f0369_b.jpg)

![img](https://pic4.zhimg.com/v2-03cc9fa82a7a609408aca212b895d437_b.jpg)

堆的根节点是堆中元素值最小（或最大）的结点，称为堆顶顶点；从根节点到每个叶节点的路径上，元素的排序序列都是递减（或递增）有序的。

![img](https://pic2.zhimg.com/v2-8198936de84625935098c00fd83c1dfd_b.jpg)

-  建立一个堆排序的方法：

![img](https://pic4.zhimg.com/v2-9350310b1fe1cbed41527691382e2eeb_b.jpg)

![img](https://pic2.zhimg.com/v2-6ab565bc998aee8724f9ea9a931328cd_b.jpg)

![img](https://pic3.zhimg.com/v2-55622d1fbdd1d216d97c5cddf7493ab6_b.jpg)

- 堆排序的过程：

![img](https://pic4.zhimg.com/v2-48e22c84194642bfc5cc73b19bd172f7_b.jpg)

![img](https://pic2.zhimg.com/v2-228934afb8c6e511693db0605de4d801_b.jpg)

- 堆排序算法实现：

```
void HeapAdjust(int *a,int i,int size)  //调整堆 
{
    int lchild=2*i;       //i的左孩子节点序号 
    int rchild=2*i+1;     //i的右孩子节点序号 
    int max=i;            //临时变量 
    if(i<=size/2)          //如果i不是叶节点就不用进行调整 
    {
        if(lchild<=size&&a[lchild]>a[max])
        {
            max=lchild;
        }    
        if(rchild<=size&&a[rchild]>a[max])
        {
            max=rchild;
        }
        if(max!=i)
        {
            swap(a[i],a[max]);
        }
    }        
}

void BuildHeap(int *a,int size)    //建立堆 
{
    int i;
    for(i=size/2;i>=1;i--)    //非叶节点最大序号值为size/2 
    {
        HeapAdjust(a,i,size);    
    }    
} 

void HeapSort(int *a,int size)    //堆排序 
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        //cout<<a[1]<<" ";
        swap(a[1],a[i]);           //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面 
          //BuildHeap(a,i-1);        //将余下元素重新建立为大顶堆 
          HeapAdjust(a,1,i-1);      //重新调整堆顶节点成为大顶堆
    }
} 
```

![img](https://pic1.zhimg.com/v2-85bc9fc4e1f02fbc674483db81c1d2c4_b.jpg)

### 归并排序

- “归并”的含义是将两个或两个以上的有序表合并成一个新的有序表。

![img](https://pic4.zhimg.com/v2-22f3d130bbaf0652c8636de5ecb7771b_b.jpg)

![img](https://pic2.zhimg.com/v2-0be6a77668831c3fc077356c8288664d_b.jpg)

- 两个有序表的合并算法Merge()：

![img](https://pic4.zhimg.com/v2-a77545b2cdf5f7ceff3326c6840f4a9b_b.jpg)

![img](https://pic1.zhimg.com/v2-231b3b8253a854fc1f18a8c5cbb23f88_b.jpg)

![img](https://pic4.zhimg.com/v2-96b835f3e775a56923bf25d380fa18c7_b.jpg)

- 算法分析：                                                                                                 

![img](https://pic1.zhimg.com/v2-2f231ae2ab9467a488c0268c5541f5bc_b.jpg)

### 基数排序

- 基数排序是一种借助多关键字排序的思想对单逻辑关键字进行排序的方法，即先将关键字分解成若干部分，然后通过对各部分关键字的分别排序，最终完成对全部记录的排序。
- 多关键字的排序：

![img](https://pic4.zhimg.com/v2-d206b6a46d55e5ef79a45d0cf2cb0abf_b.jpg)

![img](https://pic3.zhimg.com/v2-2232659ce12832f66b2f2b0a65fcda1e_b.jpg)

- 链式基数排序：                                                               

![img](https://pic4.zhimg.com/v2-e63548dcc8884b1a9e96563f8e01a06b_b.jpg)

![img](https://pic2.zhimg.com/v2-1c55566b808ba87a7b4985cf85b932d9_b.jpg)

![img](https://pic4.zhimg.com/v2-1033d236087ef5c066b0c7aa8e68fa1f_b.jpg)

### 排序算法总结                                                                                     

![img](https://pic2.zhimg.com/v2-e42a01c7457ce1c1d0811434b369a6c5_b.jpg)