Public Class frmcollege

    Private Sub frmcollege_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
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
        '        SELECT     sno, name, clgname, sport, dob, age, gender
        'FROM         dbo.tbl_streg
        'WHERE     (clgname = N'st.aloysius') AND (sport = N'CRICKET')
        i = 0
        DataGridView1.Rows.Clear()

        sql = "select * from tbl_streg where clgname='" & cmdcollege.Text & "' and sport='" & cmdsport.Text & "'"
        If rs.State = 1 Then rs.Close()
        rs.Open(sql, conn)
        Do While rs.EOF = False
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

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        frmbest.Show()

    End Sub
End Class