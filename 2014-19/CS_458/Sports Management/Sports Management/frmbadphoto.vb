Public Class frmbadphoto

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        With Me.OpenFileDialog1.Filter = "all files | *.*"
            If OpenFileDialog1.ShowDialog() = Windows.Forms.DialogResult.OK Then
                txtphoto.Text = OpenFileDialog1.FileName
            End If
        End With
    End Sub

    Private Sub txtphoto_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles txtphoto.TextChanged
        PictureBox1.ImageLocation = txtphoto.Text
    End Sub

    Private Sub frmbadphoto_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        opendb()
        loadgrid()

    End Sub
    Sub loadgrid()
        sql = "select * from tbl_badminton"
        If rs.State = 1 Then rs.Close()
        rs.Open(sql, conn)
        DataGridView1.Rows.Clear()
        Dim i
        i = 0
        Do While Not rs.EOF
            DataGridView1.Rows.Add()
            DataGridView1.Item(0, i).Value = rs(0).Value
            'DataGridView1.Item(1, i).Value = rs(1).Value
            'DataGridView1.Item(2, i).Value = rs(2).Value
            'DataGridView1.Item(3, i).Value = rs(3).Value

            rs.MoveNext()
            i = i + 1

        Loop
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        sql = "insert into tbl_badminton(photo)"
        sql = sql & " values('" & txtphoto.Text & "')"
        conn.Execute(sql)
        MsgBox("saved")
        clear()

        loadgrid()
    End Sub

    Private Sub DataGridView1_CellClick(ByVal sender As Object, ByVal e As System.Windows.Forms.DataGridViewCellEventArgs) Handles DataGridView1.CellClick
        txtphoto.Text = DataGridView1.CurrentRow.Cells(0).Value
    End Sub
    Sub clear()
        txtphoto.Text = ""

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        sql = "delete from tbl_badminton where photo='" & DataGridView1.CurrentRow.Cells(0).Value & "'"
        conn.Execute(sql)
        MsgBox("deleted successfully")
        clear()
        loadgrid()

    End Sub
End Class