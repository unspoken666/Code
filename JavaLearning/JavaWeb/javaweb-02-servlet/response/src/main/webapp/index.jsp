<html>
<body>
<h2>Hello World!</h2>

<%--这里提交的路径，需要寸照到项目的路径--%>
<%--${pageContext.request.contextPath}代表当前的项目--%>
<form action="${pageContext.request.contextPath}/login" method="get">
    <%@ page contentType="text/html; charset=UTF-8" %>
    用户名:<input type="text" name="username"><br>
    密码:<input type="password" name="password"><br>
    <input type="submit">
</form>


</body>
</html>
