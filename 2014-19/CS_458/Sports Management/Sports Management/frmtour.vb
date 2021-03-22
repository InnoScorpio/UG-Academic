Public Class frmtour

    Private Sub frmtour_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        opendb()
        loadgrid()


    End Sub
    Sub loadgrid()
        sql = "select * from tbl_tour"
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
    Sub clear()
        txttour.Text = ""
        txtvenue.Text = ""
        DateTimePicker1.Value = Today.Date

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        clear()

    End Sub

    Private Sub DataGridView1_CellClick(ByVal sender As Object, ByVal e As System.Windows.Forms.DataGridViewCellEventArgs) Handles DataGridView1.CellClick
        txttour.Text = DataGridView1.CurrentRow.Cells(1).Value
        DateTimePicker1.Value = DataGridView1.CurrentRow.Cells(2).Value
        txtvenue.Text = DataGridView1.CurrentRow.Cells(3).Value

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        If txttour.Text = "" Then
            MsgBox("enter the tournament name")
        ElseIf txtvenue.Text = "" Then
            MsgBox("enter the venue")
        Else
            sql = "insert into tbl_tour(tournament,date,venue)"
            sql = sql & " values('" & txttour.Text & "',convert(date,'" & DateTimePicker1.Value & "',103),'" & txtvenue.Text & "')"
            conn.Execute(sql)
            MsgBox("record added")
            clear()
            loadgrid()

        End If
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        sql = "update tbl_tour set tournament = '" & txttour.Text & "',date= convert(date,'" & DateTimePicker1.Value & "',103), venue= '" & txtvenue.Text & "' where tno='" & DataGridView1.CurrentRow.Cells(0).Value & "'"
        conn.Execute(sql)
        MsgBox("record updated")
        clear()
        loadgrid()

    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        sql = "delete from tbl_tour where tno='" & DataGridView1.CurrentRow.Cells(0).Value & "'"
        conn.Execute(sql)
        MsgBox("record deleted")
        clear()
        loadgrid()

    End Sub

    Private Sub DateTimePicker1_ValueChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles DateTimePicker1.ValueChanged


    End Sub
End Class