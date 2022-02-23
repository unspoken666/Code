<%--
  Created by IntelliJ IDEA.
  User: Unspoken
  Date: 2021/7/26
  Time: 16:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登录</title>
</head>
<body>
<h1>登录</h1>

<div>
<%--    这里表单表示的意思：以post方式提交表单，提交到我们的login请求--%>
    <form action="${pageContext.request.contextPath}/login" method="post">
        <%@ page contentType="text/html;charset=UTF-8" language="java" %>
        用户名：<input type="text" name="username"> <br>
        密码：<input type="password" name="password"> <br>
        爱好：
        <input type="checkbox" name="hobbies" value="女孩">女孩
        <input type="checkbox" name="hobbies" value="代码">代码
        <input type="checkbox" name="hobbies" value="唱歌">唱歌
        <input type="checkbox" name="hobbies" value="电影">电影

        <br>
        <input type="submit">
    </form>


</div>
</body>
</html>
