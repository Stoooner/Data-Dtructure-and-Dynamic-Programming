## 动态规划题目特点
>1. 计数:
>- 有多少种方式走到右下角;
>- 有多少种方法选出$k$个数使得和为sum;
>2. 求最大最小值:
>- 从左上角走到右下角路径的最大数字和;
>- 最长上升子序列长度;
>3. 求存在性:
>- 取石子游戏，先手是否必胜(也即问的是先手是否存在必胜的策略);
>- 能不能选出$k$个数使得和是sum;

## 动态规划组成部分
>1. 组成部分1——确定状态(需要两个意识)：
    - **最后一步**；
    - **子问题**；
>2. 以coin change问题为例：
    - **最后一步**：最后一枚硬币拼出了$a_k$元钱；
    - **子问题**：最少用多少枚硬币可以拼出$27-a_k$元钱；
    - **原问题**：最少用多少枚硬币可以拼出$27$元钱；
    - 因此将原问题转换为了一个子问题，且规模缩小了：$27-a_k$
    - 为了简化定义，我们设状态$$f(X) = 最少用多少枚硬币可以拼出X元.$$
    - 由于硬币的面值$a_k$只有$2, 5, 7$元三种情况，因此需要求的最少硬币数为：$$f(27) = min\{f(27-2)+1, f(27-5)+1, f(27-7)+1\}$$
>3. 组成部分2——转移方程：
    ![1610416783497.png](img\1610416783497.png)
>4. 组成部分3——初始条件和边界情况：
    ![1610416963847.png](img\1610416963847.png)
>5. 组成部分4——计算顺序：
    - **一般在动态规划**中计算顺序都是从小到大的顺序进行计算的；
    - 好处就是，在计算$f(X)$时，$f(X-2)、f(X-5)以及f(X-7)$都是以及计算过了的；
>6. 总结：
    ![1610417446694.png](img\1610417446694.png)
    ![1610421892004.png](img\1610421892004.png)

