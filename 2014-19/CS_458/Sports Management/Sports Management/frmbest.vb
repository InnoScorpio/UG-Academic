Public Class frmbest

    Private Sub frmbest_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        opendb()
        collegename()
        sport()

    End Sub
    Sub collegename()
        cmdcollege.Items.Clear()
        sql = "select distinct clgname from tbl_streg "
        If rs.State = 1 Then rs.Close()
        rs.Open(sql, conn)
        Do While rs.EOF = False
            cmdcollege.Items.Add(rs(0).Value)
            rs.MoveNext()
        Loop
    End Sub
    Sub sport()
        cmdsport.Items.Clear()
        sql = "select distinct sport from tbl_streg "
        If rs.State = 1 Then rs.Close()
        rs.Open(sql, conn)
        Do While rs.EOF = False
            cmdsport.Items.Add(rs(0).Value)
            rs.MoveNext()
        Loop
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        i = 0
        dgvpro.Rows.Clear()

        sql = "select sno,name,clgname,age from tbl_streg where clgname='" & cmdcollege.Text & "' and sport='" & cmdsport.Text & "'"
        If rs.State = 1 Then rs.Close()
        rs.Open(sql, conn)
        Do While rs.EOF = False
            dgvpro.Rows.Add()
            dgvpro.Item(0, i).Value = rs(0).Value
            dgvpro.Item(1, i).Value = rs(1).Value
            dgvpro.Item(2, i).Value = rs(2).Value
            dgvpro.Item(3, i).Value = rs(3).Value
            'DataGridView1.Item(4, i).Value = rs(4).Value
            'DataGridView1.Item(5, i).Value = rs(5).Value
            'DataGridView1.Item(6, i).Value = rs(6).Value
            rs.MoveNext()
            i = i + 1
        Loop

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'sql = "insert into tbl_best(sport,name,clgname,age)"
        'sql = sql & " values('" & cmdsport.Text & "','" & txtorderno.Text & "','" & txtname.Text & "','" & txtroute.Text & "',convert(date,'" & DateTimePicker1.Value & "',103),'" & txtorder.Text & "',0)"
        'conn.Execute(sql)

        For a = 0 To dgvpro.Rows.Count - 1


            If dgvpro.Rows(a).Cells(4).Value = "True" Then

                sql = "insert into tbl_best(sport,name,clgname,age)"
                sql = sql & " values ('" & cmdsport.Text & "', '" & dgvpro.Rows(a).Cells(1).Value & "','" & dgvpro.Rows(a).Cells(2).Value & "','" & dgvpro.Rows(a).Cells(3).Value & "')"
                conn.Execute(sql)




            End If
        Next
        MsgBox("saved successfully")

    End Sub
End Class