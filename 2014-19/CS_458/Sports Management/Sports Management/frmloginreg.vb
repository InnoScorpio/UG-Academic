Public Class frmloginreg

    Private Sub frmloginreg_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        opendb()
        loadgrid()

    End Sub
    Sub loadgrid()
        sql = "select * from tbl_reg"
        If rs.State = 1 Then rs.Close()
        rs.Open(sql, conn)
        DataGridView1.Rows.Clear()
        Dim i
        i = 0
        Do While Not rs.EOF
            DataGridView1.Rows.Add()
            DataGridView1.Item(0, i).Value = rs(0).Value
            DataGridView1.Item(1, i).Value = rs(1).Value
            DataGridView1.Item(2, i).Value = rs(2).Value
            DataGridView1.Item(3, i).Value = rs(3).Value
         
            rs.MoveNext()
            i = i + 1

        Loop
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        clear()

    End Sub
    Sub clear()
        cmdutype.SelectedIndex = -1
        txtuname.Text = ""
        txtpass.Text = ""

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        If cmdutype.Text = "" Then
            MsgBox("select usertype")
        ElseIf txtuname.Text = "" Then
            MsgBox("enter username")
        ElseIf txtpass.Text = "" Then
            MsgBox("enter password")
        Else
            sql = "insert into tbl_reg(usertype,username,password)"
            sql = sql & " values('" & cmdutype.Text & "','" & txtuname.Text & "','" & txtpass.Text & "')"
            conn.Execute(sql)
            MsgBox("record added")
            clear()
            loadgrid()



        End If
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        sql = "update tbl_reg set usertype='" & cmdutype.Text & "',username='" & txtuname.Text & "',password='" & txtpass.Text & "' where id= '" & DataGridView1.CurrentRow.Cells(0).Value & "'"
        conn.Execute(sql)
        MsgBox("record updated")
        clear()
        loadgrid()


    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        sql = "delete from tbl_reg where id='" & DataGridView1.CurrentRow.Cells(0).Value & "'"
        conn.Execute(sql)
        MsgBox("record deleted")
        clear()
        loadgrid()


    End Sub

    Private Sub DataGridView1_CellClick(ByVal sender As Object, ByVal e As System.Windows.Forms.DataGridViewCellEventArgs) Handles DataGridView1.CellClick
        cmdutype.Text = DataGridView1.CurrentRow.Cells(1).Value
        txtuname.Text = DataGridView1.CurrentRow.Cells(2).Value
        txtpass.Text = DataGridView1.CurrentRow.Cells(3).Value

    End Sub
End Class