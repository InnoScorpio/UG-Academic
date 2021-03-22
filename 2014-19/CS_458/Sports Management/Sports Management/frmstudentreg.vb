Public Class frmstudentreg

    Private Sub Label1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Label1.Click

    End Sub

    Private Sub frmstudentreg_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        opendb()
        loadgrid()
        sno()


    End Sub
    Sub sno()
        Dim j
        j = 1
        txtsno.Text = j
        sql = "select max(sno) from tbl_streg"
        If rs.State = 1 Then rs.Close()
        rs.Open(sql, conn)
        If rs.EOF = False Then
            j = rs(0).Value
            j = j + 1
            txtsno.Text = j
        End If
    End Sub
    Sub loadgrid()
        sql = "select * from tbl_streg"
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
            DataGridView1.Item(4, i).Value = rs(4).Value
            DataGridView1.Item(5, i).Value = rs(5).Value
            DataGridView1.Item(6, i).Value = rs(6).Value
            rs.MoveNext()
            i = i + 1

        Loop
    End Sub

    Private Sub DataGridView1_CellClick(ByVal sender As Object, ByVal e As System.Windows.Forms.DataGridViewCellEventArgs) Handles DataGridView1.CellClick
        txtsno.Text = DataGridView1.CurrentRow.Cells(0).Value
        txtname.Text = DataGridView1.CurrentRow.Cells(1).Value
        txtclgname.Text = DataGridView1.CurrentRow.Cells(2).Value
        cmdsport.Text = DataGridView1.CurrentRow.Cells(3).Value
        DateTimePicker1.Value = DataGridView1.CurrentRow.Cells(4).Value
        txtage.Text = DataGridView1.CurrentRow.Cells(5).Value
        cmdgender.Text = DataGridView1.CurrentRow.Cells(6).Value

    End Sub

    Private Sub DataGridView1_CellContentClick(ByVal sender As System.Object, ByVal e As System.Windows.Forms.DataGridViewCellEventArgs) Handles DataGridView1.CellContentClick

    End Sub

    Private Sub TextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles txtname.TextChanged

    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        clear()


    End Sub
    Sub clear()
        txtsno.Text = ""
        txtname.Text = ""
        txtclgname.Text = ""
        cmdsport.SelectedIndex = -1
        DateTimePicker1.Value = Today.Date
        txtage.Text = ""
        cmdgender.SelectedIndex = -1


    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        If txtsno.Text = "" Then
            MsgBox("enter student no")
        ElseIf txtname.Text = "" Then
            MsgBox("enter student name")
        ElseIf txtclgname.Text = "'" Then
            MsgBox("enter college name")
        ElseIf txtage.Text = "" Then
            MsgBox("age is not calculated")
        ElseIf cmdsport.Text = "" Then
            MsgBox("select sport")
        ElseIf cmdgender.Text = "" Then
            MsgBox("select gender")


        Else
           



            sql = "insert into tbl_streg(sno,name,clgname,sport,dob,age,gender)"
            sql = sql & " values('" & txtsno.Text & "','" & txtname.Text & "','" & txtclgname.Text & "','" & cmdsport.Text & "', convert(date,'" & DateTimePicker1.Value & "',103),'" & txtage.Text & "','" & cmdgender.Text & "')"
            conn.Execute(sql)
            MsgBox("Record added")
            clear()
            sno()

            loadgrid()
        End If

    End Sub

    Private Sub DateTimePicker1_ValueChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles DateTimePicker1.ValueChanged
        Dim Age As Double = Math.Floor(DateDiff(DateInterval.Month, DateTimePicker1.Value, System.DateTime.Now) / 12)
        txtage.Text = Age

    End Sub

    Private Sub txtage_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles txtage.TextChanged
      

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        sql = "update tbl_streg set name='" & txtname.Text & "',clgname='" & txtclgname.Text & "', sport='" & cmdsport.Text & "',dob=convert(date,'" & DateTimePicker1.Text & "',103),age='" & txtage.Text & "',gender='" & cmdgender.Text & "' where sno='" & txtsno.Text & "'"
        conn.Execute(sql)
        MsgBox("record updated")
        clear()
        sno()

        loadgrid()

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        sql = "delete from tbl_streg where sno='" & txtsno.Text & "'"
        conn.Execute(sql)
        MsgBox("record deleted")
        clear()
        sno()

        loadgrid()

    End Sub
End Class