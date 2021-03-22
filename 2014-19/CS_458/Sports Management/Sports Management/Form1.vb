Public Class Form1

    Private Sub THROWBALLToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles THROWBALLToolStripMenuItem.Click

    End Sub

    Private Sub GAMESToolStripMenuItem1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles GAMESToolStripMenuItem1.Click
        Panel1.Visible = True
        
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Panel1.Visible = False
    End Sub

    Private Sub STUDENTREGISTRATIONToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles STUDENTREGISTRATIONToolStripMenuItem.Click
        frmstudentreg.Show()

    End Sub

    Private Sub LOGINREGISTRATIONToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LOGINREGISTRATIONToolStripMenuItem.Click
        frmloginreg.Show()

    End Sub

    Private Sub PLAYERSToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem.Click
        frmfplyr.Show()


    End Sub

    Private Sub TOURNAMENTToolStripMenuItem6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem6.Click
        frmtour.Show()

    End Sub

    Private Sub PLAYERSToolStripMenuItem1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem1.Click
        frmcplyr.Show()


    End Sub

    Private Sub Panel1_Paint(ByVal sender As System.Object, ByVal e As System.Windows.Forms.PaintEventArgs) Handles Panel1.Paint

    End Sub

    Private Sub PLAYERSToolStripMenuItem2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem2.Click
        frmvolleyplr.Show()


    End Sub

    Private Sub PLAYERSToolStripMenuItem3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem3.Click
        frmhockeyplyr.Show()


    End Sub

    Private Sub PLAYERSToolStripMenuItem4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem4.Click
        frmbad.Show()

    End Sub

    Private Sub LOGOUTToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LOGOUTToolStripMenuItem.Click
        If MsgBoxResult.No = MsgBox("DO YOU WANT TO LOGOUT?", MsgBoxStyle.YesNo, " SMS") Then Exit Sub

        Me.Close()
        frmlogin1.Show()
    End Sub

    Private Sub EXITToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles EXITToolStripMenuItem.Click
        If MsgBoxResult.No = MsgBox("DO YOU WANT TO EXIT?", MsgBoxStyle.YesNo) Then Exit Sub
        Application.Exit()
    End Sub

    Private Sub COLLEGEToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        frmcollege.Show()

    End Sub

    Private Sub COLLEGEToolStripMenuItem_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles COLLEGEToolStripMenuItem.Click
        frmcollege.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem1.Click
        frmcrtour.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem.Click
        frmfttour.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem2.Click
        frmvltour.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem3.Click
        frmhtour.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem4.Click
        frmbadtour.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem5.Click
        frmbaskettour.Show()

    End Sub

    Private Sub STATEToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles STATEToolStripMenuItem.Click
        frmstate.Show()

    End Sub
End Class
